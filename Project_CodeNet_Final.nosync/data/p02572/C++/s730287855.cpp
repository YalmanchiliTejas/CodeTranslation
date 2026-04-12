#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
int main(void){
    ll n;cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin>>a[i];
        b[n-i-1]=a[i];
    }
    
    rep(i,n-1){
        b[i+1]+=b[i];
        b[i+1]%=mod;
    }
    reverse(b.begin(),b.end());
    ll res=0;
    rep(i,n-1){
        res+=((a[i]*b[i+1])%mod);
        res%=mod;
    }
    cout<<res<<endl;
}
