#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define PII pair<int,int>
#define s second
#define f first
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x)%MOD;
        }
        p = p >> 1;
        x = (x*x)%MOD;
    }
    return res;
}
void add_self(ll &a, ll b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
}
string k;
int d;
ll dp[100005][101][2];
ll solve(int index, int rem, int flag){
    if(index == k.size()){
        return rem == 0;
    }
    if(dp[index][rem][flag] != -1){
        return dp[index][rem][flag];
    }
    ll ans = 0;
    int num = (k[index] - '0');
    for(int i = 0; i < ((!flag) ? num : 10); i++){
        add_self(ans,solve(index+1, (rem + i)%d, 1));
    }
    if(!flag){
        add_self(ans, solve(index+1, (rem+num)%d, flag));
    }
    return dp[index][rem][flag] = ans;
}
int main() {
    IO;
    memset(dp, -1, sizeof dp);
    cin  >> k >> d;
    cout << (solve(0, 0,  0)-1+MOD)%MOD;



    return 0;
}
