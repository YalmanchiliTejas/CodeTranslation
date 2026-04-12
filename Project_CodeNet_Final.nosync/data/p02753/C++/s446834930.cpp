#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    char s[3]={};
    scanf("%s",s);
    if(s[0]==s[1] && s[1]==s[2])cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}