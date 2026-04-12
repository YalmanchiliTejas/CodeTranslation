#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
#include<cmath>

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pb push_back

using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const int MAX_N=9;
const ll LINF=100000000000000000;

vector<int> edge[MAX_N];
int N,cnt;

void dfs(int passed,int now){
  if(passed==(1<<N)-1){
    cnt++; return;
  }
  rep(i,edge[now].size()){
    if((passed & (1<<edge[now][i]))==0) dfs(passed | (1<<edge[now][i]),edge[now][i]);
  }
}

int main(){
  int M;
  cin >> N >> M;
  rep(i,M){
    int a,b;
    cin >> a >> b ;
    a--; b--;
    edge[a].pb(b); edge[b].pb(a);
  }
  dfs(1,0);
  cout << cnt << endl;

  return 0;
}
