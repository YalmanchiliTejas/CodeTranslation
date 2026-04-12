#include<bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n) for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

vector<VI> G;
int n, m;
bool memo[8];

int dfs(int now){
    memo[now] = true;
    int cnt = 0;
    REP(i, 8) cnt += memo[i];
    if(cnt == 8){
        memo[now] = false;
        return 1;
    }

    int res = 0;
    REP(i, G[now].size()){
        int next = G[now][i];
        if(memo[next]) continue;
        res += dfs(next);
    }
    memo[now] = false;
    return res;
}

int main(){
    cin >> n >> m;
    REP(i, n){
        VI tmp;
        G.PB(tmp);
        memo[i] = false;
    }
    REP2(i, n, 8){
        memo[i] = true;
    }
    REP(i, m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].PB(b);
        G[b].PB(a);
    }

    cout << dfs(0) << endl;
}
