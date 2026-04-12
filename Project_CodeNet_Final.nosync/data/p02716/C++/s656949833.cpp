#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (long long) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define MAXN 5000000
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<double> vd;
typedef vector<pii> vii;
const long long mod = 1000000007;
int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
ll pow(ll a,ll b,ll mod){
    ll ans = 1;
    while(b){
        if(b&1)
            ans*= a;
        ans%= mod;
        a*= a;
        a%= mod;
        b/=2;
    }
    return ans;
}
int main(){
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> prefix(n,0);
    prefix[0] = v[0];
    prefix[1] = v[1];
    vector<ll> dp(n,0);
    dp[0] = 0;
    dp[1] = max(v[0],v[1]);

    for(int i = 2;i<n;i++){
        prefix[i] = v[i]+prefix[i-2];
        if(i&1){
            dp[i] = max(v[i]+dp[i-2],prefix[i-1]);
        }
        else{
            dp[i] = max(dp[i-2]+v[i],dp[i-1]);
        }
    }
    cout<<dp[n-1];
    return 0;
}