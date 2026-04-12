#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define ll long long
#define ld long double
#define pll pair<ll ,ll >
#define pii pair<int, int> 
#define mod 1000000007
ll power(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b%2!=0) res=(res*a)%mod;
        a=(a*a);
        b/=2;
    }
    return res;
}
ll ncr(ll n,ll k){
    if(k==0||k==n) return 1ll;
    if(k>n-k) k=n-k;
    ll pro=1;
    for(ll i=0;i<k;i++){
        pro=(pro*(n-i));
        pro/=(i+1);
    }
    return pro;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    if(n==3 || n==5 || n==7) cout<<"YES";
    else cout<<"NO";
    return 0;
}
