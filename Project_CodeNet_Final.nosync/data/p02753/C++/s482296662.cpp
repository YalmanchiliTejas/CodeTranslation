#include <bits/stdc++.h>
using namespace std;
int a;
char s[3];
int main(){
    for(int i=0;i<3;i++){
        cin>>s[i];
        if(s[i]=='A')a++;
    }
    if(a!=3&&a!=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}