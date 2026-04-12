#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
 
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
 
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
 
const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

LL burger[51];
LL Pcount[51];

LL dfs(LL depth, LL idx, LL X, LL prev_idx){
    //cout << depth << " : " << idx << " : " << X << " : " << prev_idx << endl;
    if(X == 0) return 0;
    if(depth == 1) {
        if(1 <= X - idx) return 3;
        if(0 == X - idx) return 2;
        if(-1 == X - idx) return 1;
        return 0;
    }
    if(idx == X) { return Pcount[depth - 1] + 1; }
    if(idx < X){ return Pcount[depth - 1] + 1 + dfs(depth-1, idx + burger[depth - 1] / 2 + 1, X, idx); }
    return dfs(depth - 1, (idx - prev_idx + 1) / 2 + prev_idx - 1, X - 1, prev_idx);
}

void solve(long long N, long long X){
    burger[0] = 1;
    Pcount[0] = 1;

    REP(i, N){
        burger[i+1] = burger[i] * 2 + 3;
        Pcount[i+1] = Pcount[i] * 2 + 1;
    }

    LL ans = dfs(N, burger[N-1]+1, X-1, 0);
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    solve(N, X);
    return 0;
}
