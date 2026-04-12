
#include <cstdio>

int main(){
    char c;
    scanf("%c",&c);
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
        printf("vowel");
    }
    else{
        printf("consonant");
    }
    printf("\n");

    return 0;
}