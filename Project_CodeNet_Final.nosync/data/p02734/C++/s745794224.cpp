//
// Created by yamunaku on 2020/03/22.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    //CFS;
    int n, s;
    cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];
    vl dp(s + 1, 0);
    dp[0] = 1;
    rep(i, n){
        if(a[i] > s) continue;
        if(s == a[i]){
            dp[s] = (dp[s] + (i + 1) * (n - i)) % MOD;
            continue;
        }
        dp[s] = (dp[s] + dp[s - a[i]] * (n - i)) % MOD;
        perl(j, a[i] + 1, s){
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
        dp[a[i]] = (dp[a[i]] + dp[0] * (i + 1)) % MOD;
    }
    cout << dp[s] << endl;
    return 0;
}