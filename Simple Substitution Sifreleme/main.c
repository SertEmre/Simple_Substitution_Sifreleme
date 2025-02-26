#include <stdio.h>
#include <string.h>
#define ALFABE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ANAHTAR "QWERTYUIOPASDFGHJKLZXCVBNM"

void sifrele(char metin[]);
void desifrele(char metin[]);

int main() {
    char metin[100];
    int secim;

    printf("Basit Substitution Sifreleme\n");
    printf("1. Sifrele\n");
    printf("2. Sifreyi coz\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);
    getchar(); // Buffer temizleme

    printf("Bir metin giriniz: ");
    fgets(metin, sizeof(metin), stdin);
    metin[strcspn(metin, "\n")] = '\0';

    if (secim == 1) {
        sifrele(metin);
        printf("SifrelenmiS metin: %s\n", metin);
    } else if (secim == 2) {
        desifrele(metin);
        printf("Sifresi Cozulmus metin: %s\n", metin);
    } else {
        printf("Gecersiz secim.\n");
    }

    return 0;
}

// Þifreleme fonksiyonu
void sifrele(char metin[]) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = ANAHTAR[metin[i] - 'A'];
        } else if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = ANAHTAR[metin[i] - 'a'] + 32;
        }
    }
}

// Þifre çözme fonksiyonu
void desifrele(char metin[]) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'A' && metin[i] <= 'Z') {
            for (int j = 0; j < 26; j++) {
                if (ANAHTAR[j] == metin[i]) {
                    metin[i] = ALFABE[j];
                    break;
                }
            }
        } else if (metin[i] >= 'a' && metin[i] <= 'z') {
            for (int j = 0; j < 26; j++) {
                if (ANAHTAR[j] == metin[i] - 32) {
                    metin[i] = ALFABE[j] + 32;
                    break;
                }
            }
        }
    }
}
