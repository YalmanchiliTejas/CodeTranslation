#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int h,w;
    cin>>h>>w;
    int cnt=0;
    rep(i,h){
        string s; cin>>s;
        rep(j,w){
            if(s[j]=='#')cnt++;
        }
    }
    if(cnt==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
