#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char str[10];
    scanf("%s",str);
    int len=strlen(str);
    int i;
    for(i=0;i<len;i++){
        if(str[i]=='A'){
            if(str[i+1]=='C'){
                break;
            }
        }
    }
    if(i==len) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
