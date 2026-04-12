#include <bits/stdc++.h>
using namespace std;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

typedef long long LL;
const LL mod=1000000007;
#define MAX 10000
#define NIL -1
const double PI  = acos(-1.0);

//-------------------------------------------
int N, M; // vertex , side
int a ,b;
bool G[MAX][MAX]; // graph
bool visited[MAX];

int dfs( int v, int N, bool visited[MAX]){
    //現在の頂点vからdfs

    bool all = true;

    REP(i, N){
        if (visited[i] == false)    all = false;
    }

    if (all){
        return 1;   //pathが1通りある
    }

    int path = 0;

    REP(i, N){
        if (G[v][i] == false) continue; //隣接じゃないならパス
        if (visited[i]) continue;   //訪問済ならパス

        //現在の頂点vと隣接のiが未訪問なら
        visited[i] = true;  //訪問済化
        path += dfs( i, N, visited); //iからdfs
        visited[i] = false ;    //未訪問化
    }
    return path;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, M){
        cin >> a >> b;
        G[a-1][b-1] = G[b-1][a-1] = true; //rinsetsu matrix
    }

    //探索判定配列の初期化
    memset( visited, N, false);
    visited[0] = true;

    cout << dfs(0, N, visited);

    return 0;
}
