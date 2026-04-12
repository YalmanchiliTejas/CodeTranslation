#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    char s;
    s = getchar();
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        printf("vowel\n");
    else printf("consonant\n");
    return 0;
}
