#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
    string str;
    cin>>str;
    int cc1=0,cc2=0;
    for(int i=0;i<3;i++){
        if(str[i]=='A')cc1++;
        else{
            cc2++;
        }
    }
    if(cc1&&cc2){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}