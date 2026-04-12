// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << " = " << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define SP << " " <<

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;

const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> inline T ceil(T a, T b) {return T((a + b - 1)/b);}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }

int nmax=200000; // 2*(10^5)
vvec g(nmax);

ll dp[200200][2];
ll dp2[200200][2][2];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1){
        dp[i][0]=dp[i][1]=-INF;
        dp2[i][0][0]=dp2[i][0][1]=dp2[i][1][0]=dp2[i][1][1]=-INF;
    }
    int m=n/2;
    if(n%2==0){
        dp[1][0]=a[0];
        dp[1][1]=a[1];
        for(int i=1;i<m;i++){
            for(int j=0;j<2;j++){
                if(j==0) chmax(dp[i+1][0],dp[i][j]+a[2*i]);
                chmax(dp[i+1][1],dp[i][j]+a[2*i+1]);
            }
        }
        cout<<max(dp[m][0],dp[m][1]);
    }
    else{
        // a[n-1]を使わない場合　上の偶数の場合と一緒
        dp[1][0]=a[0],dp[1][1]=a[1];
        for(int i=1;i<m;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i+1][0]=max(dp[i+1][0],dp[i][j]+a[2*i]);
                }
                dp[i+1][1]=max(dp[i+1][1],dp[i][j]+a[2*i+1]);
            }
        }
        // a[n-1]を使う場合
        dp2[1][0][0]=a[n-1]+a[0],dp2[1][1][0]=a[n-1]+a[1];
        dp2[1][0][1]=a[n-1];
        for(int i=1;i<m;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    if(k==0){
                        dp2[i+1][0][1]=max(dp2[i+1][0][1],dp2[i][j][k]);
                    }
                    if(j==0){
                        dp2[i+1][0][k]=max(dp2[i+1][0][k],dp2[i][j][k]+a[i*2]);
                    }
                    // a[n-2]は使えない事に注意！
                    if(i!=m-1)dp2[i+1][1][k]=max(dp2[i+1][1][k],dp2[i][j][k]+a[i*2+1]);
                }
            }
        }
        cout << max({dp[m][0],dp[m][1],dp2[m][0][1],dp2[m][1][1]}) << endl;
    }

    
}