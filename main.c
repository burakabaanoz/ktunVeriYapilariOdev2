#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Dugum{
    char veri;
    struct Dugum *sonraki;
    struct Dugum *onceki;
};

struct Dugum *top = NULL;

void push(char veri){
    struct Dugum *yeniDugum = (struct Dugum *)malloc(sizeof(struct Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = top;
    yeniDugum->onceki = NULL;

    if(top != NULL) {
        top->onceki = yeniDugum;
    }

    top = yeniDugum;
}

char pop(){
    if(top == NULL) {
        printf("Yigin bos, eleman poplanamaz.\n");
        return '\0'; // Hata durumu
    }

    char veri = top->veri;
    struct Dugum *gecici = top;
    top = top->sonraki;
    free(gecici);

    return veri;
}
char rastgele_sesli_harf(){
    char sesli_harfler[] = {'a', 'e', 'i', 'o', 'u'};
    return sesli_harfler[rand() % 5];
}

char rastgele_sessiz_harf(){
    char sessiz_harfler[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    return sessiz_harfler[rand() % 21];
}


int main(){
    srand(time(NULL));

    char rastgeleHarfler[10];
    char harf;

    for(int i = 0; i < 5; ++i) {
        rastgeleHarfler[i] = rastgele_sesli_harf();
    }

    for(int i = 5; i < 10; ++i) {
        rastgeleHarfler[i] = rastgele_sessiz_harf();
    }

    printf("Rastgele Harfler:\n");

    for(int i=0;i<10;i++){
        printf("%c ",rastgeleHarfler[i]);
    }
   

    printf("\nYigin Islemi:\n");

    for(int i=0;i<6;i++){
        if(top==NULL){
            harf = rastgeleHarfler[rand()%10];
            push(harf);
            printf("%c : eklenen eleman\n",harf);
        }
        else{
            if(top->veri == 'a' || top->veri == 'e' || top->veri == 'i' || top->veri == 'o' || top->veri == 'u' ){
                harf = rastgeleHarfler[rand()%10];
                push(harf);
                while(top->veri == 'a' || top->veri == 'e' | top->veri == 'i' || top->veri == 'o' || top->veri == 'u'){
                    pop();
                    harf = rastgeleHarfler[rand()%10];
                    push(harf);
                }
                printf("%c : eklenen eleman\n",harf);
            }
            else{
                harf = rastgeleHarfler[rand()%10];
                push(harf);
                while(top->veri != 'a' && top->veri != 'e' && top->veri != 'i' && top->veri != 'o' && top->veri != 'u'){
                    pop();
                    harf = rastgeleHarfler[rand()%10];
                    push(harf);
                }
                printf("%c : eklenen eleman\n",harf);
            }
        }
        
        
    }

    printf("\nYigindan cikartilan Elemanlar:\n");

    while(top != NULL){
        printf("Eleman: %c\n", pop());
    }

    return 0;
}
