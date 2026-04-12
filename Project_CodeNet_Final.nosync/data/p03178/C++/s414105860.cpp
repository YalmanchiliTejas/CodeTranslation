#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 10004
#define M 102
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second

string s;
vector <ll> num;
ll n, d;
ll dp[N][M][2];

ll get(int pos, ll sum, bool flag){
    ll &ans = dp[pos][sum][flag];
    if(pos == n && sum%d == 0){
        return (ans = 1);
    }
    if(pos == n && sum%d != 0){
        return (ans = 0);
    }
    if(ans != -1){
        return ans;
    }
    ans = 0;
    int lim = flag ? 9 : num[pos];
    for(int i=0; i<=lim; i++){
        ans = (ans + get(pos+1, (sum+i)%d, flag | (i < num[pos]))) % MOD;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>s>>d;
    for(auto it : s){
        num.pb(it-'0');
    }
    n = num.size();
    memset(dp, -1, sizeof dp);
    cout<<(get(0, 0, 0) - 1 + MOD)%MOD;
    return 0;
}