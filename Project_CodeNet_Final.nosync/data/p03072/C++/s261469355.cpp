#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
using namespace std;

int main() {
    ll n;
    cin>>n;
    ll max=0;
    ll sum=0;
    rep(i,n){
        ll now;
        cin>>now;
        if(max<=now){
            sum++;
            max=now;
        }
    }
    cout<<sum<<endl;
}
