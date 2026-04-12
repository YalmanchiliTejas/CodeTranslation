#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;

int dp[105][4][2];

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

string S; cin >> S;
int N = S.size();
int K; cin >> K;

dp[0][0][0] = 1;
rep(i,N)rep(j,4)rep(k,2) {
    int D = S[i] - '0';
    rep(d, 10) {
        int ni = i+1, nj = j, nk = k;
        if(d != 0) nj++;
        if(nj > K) continue;
        if(k == 0) {
            if(d > D) continue;
            if(d < D) nk = 1;
        }
        dp[ni][nj][nk] += dp[i][j][k];
    }
}
int ans = dp[N][K][0] + dp[N][K][1];
cout << ans << endl;
return 0;
}