#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    string n;
    int K;
    cin >> n >> K;

    int l = n.size();
    if(K > l) {
        cout << 0 << endl;
        return 0;
    }
    V(vvi) dp(105, vvi(2, vi(105, 0)));
    dp[0][0][0] = 1;

    rep(i, l) {
        int D = n[i]-'0';
        rep(j, 2) {
            rep(k, 105) {
                for(int d=0; d<=(j ? 9 : D); d++) {
                    if(d==0) dp[i+1][j || (d<D)][k+1] += dp[i][j][k];
                    else dp[i+1][j || (d<D)][k] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[l][0][l-K] + dp[l][1][l-K] << endl;
    
    return 0;
}