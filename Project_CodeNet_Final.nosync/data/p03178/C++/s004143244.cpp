//e4-e5-f4
//#include <boost/multiprecision/cpp_int.hpp> 
#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"
//#include "ext/pb_ds/tree_policy.hpp"
typedef long long int ll;
typedef double db;
// __int128 s128;
// __uint128_t u128;
typedef unsigned long long u64;
#define int long long int
#define PI 3.14159265359
#define sz(a) (ll)a.size()
#define lt(a) (ll)a.length()
#define pll pair<ll,ll>
#define tc(x) ll x; cin>>x; while(x--)
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define bac(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define print(a)  for (auto x : a) cout << x << " "; cout << endl
#define sl set<ll>
#define usl unordered_set<ll>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define vl vector<ll>
#define vpl vector<pll>
#define vvl vector<vector<ll>>
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define setbits(a) __builtin_popcountll(a)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define F first
#define S second
#define teevra_gati ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define P 1000000007
#define Q 1000000006
#define inf 1e18
#define N 50
#define M 105
//using namespace boost::multiprecision; 
//using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(all(v), rng);

void solve(){
    
    string s;
    cin>>s;
    ll d;
    cin>>d;
    ll n = lt(s);
    vl dp1(d,0), dp0(d,0);
    dp0[0]=1;
    f(i,0,n){
        vl dp3(d,0), dp2(d,0);
        f(j,0,d){
            ll curr = s[i]-'0';
            f(dig,0,10){ // for already small
                (dp3[(j+dig)%d] += dp1[j]) %= P;
                //cout<<i<<" "<<j<<" "<<dp3[(j+dig)%d]<<endl;
            }
            f(dig,0,curr+1){ //not yet small
                if(dig < curr) (dp3[(j+dig)%d] += dp0[j]) %= P; //this is small
                else (dp2[(j+dig)%d] += dp0[j]) %= P;
            }
        }
        dp1 = dp3;
        dp0 = dp2;
    }
    //cout<<n<<endl;
    cout<<(dp1[0] + dp0[0] - 1 + P)%P;
}

signed main() {
    teevra_gati
    
    solve();

    return 0;
}