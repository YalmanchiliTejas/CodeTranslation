#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n'
#define debug_arr(a , n) for(ll i = 0 ; i < n ; i++)cout << a[i] << " "
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<ll> 
#define inf 1000000000
#define mod 1000000007

const ll max_n = 1e5 + 9;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}

ll dp[101][2];

void add(ll &a , ll b){
    a = (a + b)%mod;
}
int main()
{
    string s;
    cin >> s;
    ll  d,  n;
    cin >> d;
    n = s.size();

    dp[0][0] = 1;
    for(ll i = 0 ; i < n ; i++){
        ll num = s[i] - '0';
        ll new_dp[101][2];
        memset(new_dp, 0 , sizeof(new_dp));
        for(ll j = 0 ; j < d ; j++){
            for(ll k = 0 ; k <= 9 ; k++){
                if(k < num){
                    add(new_dp[(j + k)%d][1] , (dp[j%d][0] + dp[j%d][1])%mod);
                }
                else if(k == num){
                    add(new_dp[(j + k)%d][0] ,dp[j%d][0]);
                    add(new_dp[(j + k)%d][1] , dp[j%d][1]);
                }
                else{
                    add(new_dp[(j + k)%d][1] , dp[j%d][1]);
                }
            }
        }     
        for(ll i = 0 ; i < 101 ; i++){
            for(ll j = 0 ; j < 2 ; j++)
                dp[i][j] = new_dp[i][j];
        }
        // debug(dp[0][0]);
        // debug(dp[0][1]);
    }

    cout << (dp[0][1] + dp[0][0] - 1 + mod)%mod<< endl;
    return 0;
}