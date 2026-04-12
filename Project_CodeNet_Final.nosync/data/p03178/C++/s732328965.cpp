#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define vl vector<ll>
#define vi vector<int>

#define ff first
#define ss second

#define pb push_back
#define MOD 1000000007 
const int nax = 1e6+5;
#define display(v) for(int i =0;i<v.size();++i)cout << v[i] << " "
#define all(v) v.begin(),v.end()

inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }

void add_self(ll &a , ll b){
    a += b;
    if(a>=MOD){
        a-=MOD;
    }
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;  cin>>str;
    int d;  cin>>d;
    vi digit;
    int n = str.length();
    for(int i =0;i<n;++i){
        digit.pb(str[i] -'0');
    }
    vector<vector<ll>> dp(d,vector<ll>(2,0));  // sum % d  and equal already
    dp[0][0]  = 1;
    for(int id = 0;id<n;++id){
        vector<vector<ll>> new_dp(d,vector<ll>(2,0));
        for(int sum = 0;sum <d;++sum){
            for(bool exceed :{false,true}){
                for(int dig =0;dig <10;++dig){
                    if(dig > digit[id] && exceed == false){
                        break;
                    }
                    add_self(new_dp[(sum+dig)%d][exceed || (dig < digit[id])] , dp[sum][exceed]);
                }
            }
        }
        dp = new_dp;
    }
    ll ans = 0;
    ans = add(dp[0][1],dp[0][0]);
    ans = sub(ans,1);
    cout << ans;
    return 0;
 }