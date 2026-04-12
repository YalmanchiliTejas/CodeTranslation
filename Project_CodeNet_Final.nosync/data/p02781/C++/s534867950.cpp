#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll dp[110][4][2];

int main(){
    string S;
    ll K;
    cin >> S >> K;
    ll N = S.size();
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    rep(i,N){
        ll c = S[i] - '0';
        rep(j,K){
            dp[i+1][j+1][1] += dp[i][j][1]*9;
        }
        rep(j,K+1){
            dp[i+1][j][1] += dp[i][j][1]*1;
        }
        if(c == 0){
            rep(j,K+1){
                dp[i+1][j][0] += dp[i][j][0];
            }
        }else{
            rep(j,K){
                dp[i+1][j+1][0] += dp[i][j][0]; 
            }
            rep(j,K+1){
                dp[i+1][j][1] += dp[i][j][0]; 
            }
            rep(j,K){
                //dp[i+1][j+1][0] += dp[i][j][0];
                dp[i+1][j+1][1] += dp[i][j][0]*(c-1);
            }
        }
    }
    cout << dp[N][K][1] + dp[N][K][0] << endl;
        /*
        rep(j,K){
            dp[i+1][j][1] += dp[i][j][0]*max((c-1), 0LL);
            if(c > 0){
                dp[i+1][j+1][1] += dp[i][j][0];
            }
        }
        rep(j,K+1){
            if(c > 0){
                dp[i+1][j][0] += dp[i][j][0];
            }
        }*/
    //}
}