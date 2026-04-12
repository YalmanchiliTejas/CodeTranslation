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
vector<pair<LL, int>> x_and_idx, y_and_idx;

struct UnionFind {
    vector<LL> data;
    UnionFind(LL size) : data(size, -1) { }

    bool unionSet(LL x, LL y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    
    bool findSet(LL x, LL y) {
        return root(x) == root(y);
    }
    
    LL root(LL x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    LL size(LL x) {
        return -data[root(x)];
    }
};

void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    REP(i, N) {
        x_and_idx.PB(MP(x[i], i));
        y_and_idx.PB(MP(y[i], i));
    }
    UnionFind uf(N);

    sort(ALL(x_and_idx));
    sort(ALL(y_and_idx));

    vector<pair<LL, pair<int, int> > > memo;
    REP(i, N-1) {
        LL now = x_and_idx[i].first;
        if(!uf.findSet(x_and_idx[i].second, x_and_idx[i+1].second)) {
            if(x_and_idx[i].first == x_and_idx[i+1].first) {
                uf.unionSet(x_and_idx[i].second, x_and_idx[i+1].second);
            }else{
                memo.PB(MP(abs(x[x_and_idx[i].second] - x[x_and_idx[i+1].second]), MP(x_and_idx[i].second, x_and_idx[i+1].second)));
            }
        }

        now = y_and_idx[i].first;
        if(uf.findSet(y_and_idx[i].second, y_and_idx[i+1].second)) continue;
        if(y_and_idx[i].first == y_and_idx[i+1].first) {
            uf.unionSet(y_and_idx[i].second, y_and_idx[i+1].second);
        }else{
            memo.PB(MP(abs(y[y_and_idx[i].second] - y[y_and_idx[i+1].second]), MP(y_and_idx[i].second, y_and_idx[i+1].second)));
        }
    }
    sort(ALL(memo));
    LL ans = 0;
    REP(i, memo.size()){
        if(uf.size(0) == N) break;
        pair<LL, pair<int, int> > now = memo[i];
        if(uf.findSet(now.second.first, now.second.second)) continue;
        ans += now.first;
        uf.unionSet(now.second.first, now.second.second);
    }

    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}
