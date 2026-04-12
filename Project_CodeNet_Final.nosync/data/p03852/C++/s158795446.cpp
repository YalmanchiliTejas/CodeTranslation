#include<ios>

int main(){
    char cC;
    scanf("%c",&cC);
    if ( cC == 'a' || cC == 'i' || cC == 'u' || cC == 'e' || cC == 'o' ) {
        printf("vowel\n");
    }else{
        printf("consonant\n");
    }
    return 0;
}
