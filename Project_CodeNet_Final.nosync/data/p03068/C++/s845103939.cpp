#include<iostream>
using namespace std;
int n,k;
char s[11],t;
string f;
main(){
    cin>>n>>s>>k;
    t=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]==t)f+=t;
        else f+='*';
    }
    cout<<f<<endl;
}