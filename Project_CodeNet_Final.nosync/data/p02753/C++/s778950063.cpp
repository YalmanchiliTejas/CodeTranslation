#include<iostream>
using namespace std;

int main(void)
{
    char s[5];
    cin>>s;
    int a = 0, b = 0;
    for(int i=0;s[i]!='\0';++i){
        if(s[i]=='A') ++a;
        else ++b;
    }
    if(a && b) puts("Yes");
    else puts("No");
    return 0;
}