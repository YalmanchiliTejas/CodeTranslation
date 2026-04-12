#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define double long double
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FORE(i,a) for(auto &i:a)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define PB push_back
#define MP make_pair
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define EACH(V,i) for(typeof((V).begin()) i=(V).begin();i!=(V).end();++i)
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
using namespace std;
using Graph=vector<vector<int>>;
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
Graph G(100010);
vector<int> deg;
vector<bool> seen; 

int main(){
  int N;
  cin>>N;
  deg.assign(N,0);
  seen.assign(N,0);
  
  REP(i,N-1){
    int a,b;
    cin>>a>>b;
    --a,--b;
    G[a].PB(b);
    G[b].PB(a);
    deg[a]++,deg[b]++;
  }
  
  bool res=true;
  queue<int> Q;
  REP(i,N){
    if(deg[i]==1) Q.push(i);
  }
  
  while(!Q.empty()){
    int v=Q.front();
    Q.pop();
    if(seen[v]) continue;
    seen[v]=true;
    
    int nv=-1;
    FORE(i,G[v]){
      if(seen[i]==false) nv=i;
    }
    if(nv==-1){
      res=false;
      break;
    }
    seen[nv]=true;
    FORE(nnv,G[nv]){
      if(seen[nnv]) continue;
      deg[nnv]--;
      if(deg[nnv]==1) Q.push(nnv);
    }
  }
  
  if(res) co("Second");
  else co("First");
  return 0;
}