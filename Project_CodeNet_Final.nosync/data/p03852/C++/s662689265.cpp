#include<bits/stdc++.h>
using namespace std;

int main(){
    char c[10];
    scanf("%s",c);
    if (c[0]=='a' || c[0]=='i' || c[0]=='u' || c[0]=='e' || c[0]=='o') {
        printf("vowel\n");
    } else {
        printf("consonant\n");
    }
    return 0;
}
