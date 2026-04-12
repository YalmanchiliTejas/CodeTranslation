#include <cstdio>

char a[] = {'a','e','i','o','u'};
char c;

int main(){
    scanf("%c", &c);


    bool f = false;
    for(int i = 0; i < 5; i++)
    if(a[i] == c) f = true;

    if(f) printf("vowel\n");
    else printf("consonant\n");

    return 0;
}
