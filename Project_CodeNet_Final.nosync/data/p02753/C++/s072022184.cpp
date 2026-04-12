#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char s[10];
    while (scanf("%s",&s)!=EOF) {
        bool flaga = false;
        bool flagb = false;
        for (int i = 0; i < 3;i++) {\
            if (s[i]=='A')
                flaga=true;
            if (s[i]=='B')
                flagb=true;
        }
        printf("%s\n",(flaga&&flagb)?"Yes":"No");
    }
    return 0;
}
