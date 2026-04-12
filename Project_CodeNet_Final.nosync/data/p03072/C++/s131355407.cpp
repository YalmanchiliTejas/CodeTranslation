#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    cin>>n;
    ll h=0;
    ll now=0;
    ll ans=0;
    rep(i,n){
        cin>>now;
        if(now>=h)ans++;
        h=max(now,h);
    }
    cout<<ans<<endl;

}

