#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    string s;
    cin>>s;
    string fs="";
    rep(0,i,3){
        string s0=s.substr(i,1);
        if(fs==""){
            fs=s0;
        }else{
            if(fs!=s0){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}