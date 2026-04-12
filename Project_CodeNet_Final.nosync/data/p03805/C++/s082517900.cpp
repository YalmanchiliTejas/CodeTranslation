#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;cin>>n>>m;
  int res=0;
  vector<vector<int>>edge(n,vector<int>(n));
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    edge[a][b]=1;
    edge[b][a]=1;
  }
  function<void(int,int)> dfs=[&](int now,int f){
    if(f==(1<<n)-1){
      res++;
      return ;
    }
    bitset<10>tf=f;
    rep(i,n){
      if(tf[i])continue;
      if(!edge[now][i])continue;
      dfs(i,f+(1<<i));
    }
  };
  dfs(0,1);
  cout<<res<<endl;

  return 0;

}
