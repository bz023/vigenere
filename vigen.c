#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY_MAX 128
#define TXT_MAX 256

void vigenere_encrypt(char key[], char text[]) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char enc_text[TXT_MAX];
    int i, j = 0;

    for (i = 0; i < text_length; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char key_char = tolower(key[j % key_length]);
            int shift = key_char - 'a';

            if (isupper(c)) {
                enc_text[i] = ((c - 'A' + shift) % 26) + 'A';
            } else {
                enc_text[i] = ((c - 'a' + shift) % 26) + 'a';
            }

            j++;
        } else {
            enc_text[i] = c;
        }
    }
    enc_text[i] = '\0';

    printf("Kódolt szöveg:   %-s\n", enc_text);
}

void vigenere_decrypt(char key[], char text[]) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char dec_text[TXT_MAX];
    int i, j = 0;

    for (i = 0; i < text_length; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char key_char = tolower(key[j % key_length]);
            int shift = key_char - 'a';

            if (isupper(c)) {
                dec_text[i] = ((c - 'A' - shift + 26) % 26) + 'A';
            } else {
                dec_text[i] = ((c - 'a' - shift + 26) % 26) + 'a';
            }

            j++;
        } else {
            dec_text[i] = c;
        }
    }
    dec_text[i] = '\0';

    printf("Dekódolt szöveg: %-s\n", dec_text);
}

int main() {
    char key[KEY_MAX];
    char text[TXT_MAX];

    printf("Kulcs:           ");
    fgets(key, KEY_MAX - 1, stdin);
    key[strcspn(key, "\n")] = '\0';

    
    printf("Szöveg:          ");
    fgets(text, TXT_MAX - 1, stdin);
    text[strcspn(text, "\n")] = '\0';

    vigenere_encrypt(key, text);

    printf("====================\n");
    printf("Kulcs:           ");
    fgets(key, KEY_MAX - 1, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("Kódolt szöveg:   ");
    fgets(text, TXT_MAX - 1, stdin);
    text[strcspn(text, "\n")] = '\0';
 
    vigenere_decrypt(key, text);

    return 0;
}
