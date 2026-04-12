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

const int N=10;
VI G[N];
bool used[N];
int n,m;
int ans=0;

void go ( int u, int cnt ) {
    if ( cnt==n ) ans++;
    used[u]=1;
    for ( int v:G[u] ) {
        if ( !used[v] ) {
            go(v,cnt+1);
        }
    }
    used[u]=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    REP(i,m) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        G[a].PB(b);
        G[b].PB(a);
    }
    go(0,1);
    cout << ans << '\n';
    return 0;
}

