#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<int, pii> viii; 
typedef vector<pll> vll; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
typedef vector<vector<vl>> vvvl; 
ll mod=1e9+7;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL);
    ll i,j,n,sum=0;
    cin>>n;
    vl a(n);
    for(i=0;i<n;i++){cin>>a[i];sum=(sum+a[i])%mod;}
    ll ans=0,curr=0;
    for(i=0;i<n;i++){
        curr=(curr+a[i])%mod;
        ans=(ans+(((sum-curr+mod)%mod)*a[i])%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
