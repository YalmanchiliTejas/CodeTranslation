#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll dp[101][4][2];

int main(){
    string S;
    ll K;
    cin >> S;
    cin >> K;
    ll N = S.size();
    //vector<vector<ll>> dp(N+1, vector<ll>(2));
    dp[0][0][0] = 1;
    rep(i,N){
        ll c = S[i] - '0';
        rep(j,10){
            rep(k,4){
                if(j == 0){
                    dp[i+1][k][1] += dp[i][k][1];
                }else{
                    if(k == 3){
                        continue;
                        //dp[i+1][k][1] += dp[i][k][1];
                    }else{
                        dp[i+1][k+1][1] += dp[i][k][1];
                    }
                }
            }
        }
        rep(j,c){
            rep(k,4){
                if(j == 0){
                    dp[i+1][k][1] += dp[i][k][0];
                }else{
                    if(k == 3){
                        continue;
                        //dp[i+1][k][1] += dp[i][k][0];
                    }else{
                        dp[i+1][k+1][1] += dp[i][k][0];
                    }
                }
            }
        }
        rep(k,3){
            if(c == 0){
                dp[i+1][k][0] += dp[i][k][0];
            }else{
                dp[i+1][k+1][0] += dp[i][k][0];
            }
        }
    }
    cout << dp[N][K][0] + dp[N][K][1] << endl;
}