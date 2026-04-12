#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    string s;
    cin>>s;
    bool T=false;
    string fs="";
    rep(0,i,3){
        if(fs=="")fs=s.substr(i,1);
        else if(s.substr(i,1)!=fs)T=true;
    }
    if(T)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}