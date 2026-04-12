#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { -1,  0, 1, 0,  1, -1,  1, -1};
static const int dy[8] = {0,  1, 0,  -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
//const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf  = 0x3f3f3f3f;

const int maxn = 5010;

int N,M;
int ed;
int st;

char G[55][55];
int vis[55][55];

bool get_input(){
    scanf("%d %d",&N,&M);
    if(!N && !M) return false;
    getchar();
    _for(i,0,N){
        fgets(G[i],55,stdin);
    }
    st = 0;
    ed = N*M*2+1;

    return true;
}

bool valid(int nx,int ny){
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) return false;
    if(G[nx][ny] == '#') return false;
    return true;
}

bool dfs(int x,int y,int dir,int goods){

    if(G[x][y] == '#') return false;

    if(x == 0 && y == 0 && goods == 3) return true;
    if(x == 0 && y == M-1 && goods == 0) goods++;
    if(x == N-1 && y == M-1 && goods == 1) goods++;
    if(x == N-1 && y == 0 && goods == 2) goods++;

    if(vis[x][y]) return false;
    vis[x][y] = 1;

    _for(i,-1,2){
        int nexd = (i + dir + 4)%4;
        int nx =  dx[nexd] + x;
        int ny =  dy[nexd] + y;
        if(valid(nx,ny)){
            if(dfs(nx,ny,nexd,goods)) return true;
        }
    }
    return false;
}

int main()
{
    while(get_input()){
        memset(vis,0,sizeof(vis));

        if(dfs(0,0,1,0)) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}

