#include<cstdio>

int main(){
    char c;
    c = getchar();
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        puts("vowel");
    else
        puts("consonant");
    return 0;
}
