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
        if(b%2!=0) res=(res*a);
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
    ll n,k;
    cin>>n>>k;
    vector<ll > siz,pat;
    siz.push_back(1ll);
    pat.push_back(1ll);
    for(int i=1;i<=n;i++){
        siz.push_back(2*siz[i-1]+3ll);
        pat.push_back(2*pat[i-1]+1ll);
    }
    ll ans=0;
    for(ll i=n;i>=0;i--){
        if(k==siz[i]){
            ans+=pat[i];
            break;
        }
        else if(k==1ll || k==0ll) {
            break;
        }
        assert(i>0);
        if(k<=1ll+siz[i-1]){
            k--;
        }
        else{
            ans+=1ll+pat[i-1];
            k-=(2ll+siz[i-1]);
        }
    }
    cout<<ans;
    return 0;
}
