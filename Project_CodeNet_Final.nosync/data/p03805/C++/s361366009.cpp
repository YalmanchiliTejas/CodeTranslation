// ABC 054 C
#include<bits/stdc++.h>
 
using namespace std;
//container util
//------------------------------------------
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).begin(),(c).end(),greater<int>())

#define PB(a) push_back(a)

#define ALL(x) (x).begin(),(x).end()
#define MAX_EL(c) *max_element((c).begin(),(c).end())
#define MIN_EL(c) *min_element((c).begin(),(c).end())
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef string str;
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const int nmax=8;
bool graph[nmax][nmax];
//Deapth First Search
//nmax(n=8),graph[i][j] should be defined as global val
//------------------------------------------
int dfs(int v,int N,bool visited[nmax]){
  bool all_visited=true;
  REP(i,N){
    if(visited[i]==false) all_visited=false;
  }
  if(all_visited) return 1;
  int ret=0;
  REP(i,N){
    if(graph[v][i]==false) continue;
    if(visited[i]) continue;
    visited[i]=true;
    ret += dfs(i,N,visited);
    visited[i]=false;
  }
  return ret;
}
//------------------------------------------

int main(){
// magic spell------------------------------
  cin.tie(0);
  ios::sync_with_stdio(false);
//------------------------------------------

  int n,m;
  cin >> n >> m;
  REP(i,m){
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1]=true;
    graph[b-1][a-1]=true;
  }
  bool visited[nmax];
  REP(i,n){
    visited[i]=false;
  }
  visited[0]=true;
  cout << dfs(0,n,visited) << endl;
  return 0;
}
