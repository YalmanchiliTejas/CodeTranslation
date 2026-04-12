#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mpr make_pair
#define mt make_tuple
 
using namespace std;
 
const ll N = 100010;
const ll mod = 1e9 + 7;
ll power(ll x, ll   y, ll p){ ll res = 1; x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;} return res; }
int d;
string k;
vector<int> digits;
ll dp[10010][2][101], used[10010][2];

void solve(int ind, int flag, int n){
    int k;
    if(ind == n)    return ;
    if(used[ind][flag]) return;
    used[ind][flag] = 1;
    solve(ind+1,flag,n);
    solve(ind+1,1-flag,n);
    k = (flag == 1) ? digits[ind] : 9;
    for(int i=0;i<=k;i++){
        for(int j=0;j<d;j++){
            if(flag && i == k)
                dp[ind][flag][(i+j)%d] += (dp[ind+1][flag][j])%mod;
            else
                dp[ind][flag][(i+j)%d] += (dp[ind+1][0][j])%mod;
        }
        for(int j=0;j<d;j++)  dp[ind][flag][j] = dp[ind][flag][j]%mod;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>d;
    memset(dp, 0, sizeof(dp));
    memset(used, 0, sizeof(used));
    for(int i=0;i<k.size();i++)    digits.pb(k[i]-'0');
    dp[k.size()][0][0] = 1;
    dp[k.size()][1][0] = 1;
    solve(0,1,k.size());
    cout<<(dp[0][1][0] - 1 + mod)%mod<<endl;
    return 0;
}