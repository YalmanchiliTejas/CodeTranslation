#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    string s; ll K; cin >> s >> K;
    ll n = s.size();

    // dp[i][j][k]; i桁目までで、0以外の数字をj個使って、k=1: kより小さい／k=0: kと等しい、を満たす個数
    vector<vvi> dp(n+1, vvi(4, vi(2, 0)));
    dp[0][0][0] = 1;
    rep(i, n){
        rep(j, 4){
            rep(k, 2){
                ll nd = s[i]-'0';
                for(ll num=0; num<10; num++){
                    ll ni=i+1, nj=j, nk=k;
                    if(num != 0) nj++;
                    if(nj > K) continue;
                    if(k == 0){
                        if(num > nd) continue;
                        if(num < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][K][0]+dp[n][K][1] << endl;
}