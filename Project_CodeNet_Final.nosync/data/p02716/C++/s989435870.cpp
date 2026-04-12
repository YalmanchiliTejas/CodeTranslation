#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for(int i=a; i<=(int)(b); i++)
#define ALL(x) begin(x),end(x)
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

template<class T> inline bool chmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

const int N=2e5+10;
const LL INF=1e18;
int a[N];
LL dp[N][4];
int main() {
    // O選，X不選
    // O X O X O X O X O 
    // 其中再多插入1，2個X
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    REP(i,n) cin >> a[i];
    int k=1+n%2; // 奇數：插入2個X 偶數：插入1個X
    REP(i,n+1) REP(j,k+1) {
        dp[i][j]=-INF;
    }
    dp[0][0]=0;
    REP(i,n) {
        REP(j,k+1) {
            chmax(dp[i+1][j+1], dp[i][j]); // 不選ai
            LL now=dp[i][j];
            if ( (i+j)%2==0 ) now+=a[i]; 
            chmax(dp[i+1][j], now);
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}