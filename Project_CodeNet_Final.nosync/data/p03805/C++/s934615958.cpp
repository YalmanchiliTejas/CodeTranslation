//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=200003;

map<ll,ll> primefactor(ll n){
  map<ll,ll> res;
  for( ll i=2LL ;i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n/=i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}


vector<int> g[10];
int n,m;
int dfs(int s,int bit){
  if(bit==(1<<n)-1)return 1;
  int res=0;
  for(int i=0;i<g[s].size();i++){
    if(!(bit>>g[s][i]&1)  ){
      res+=dfs(g[s][i],bit | (1<<g[s][i]));
    }
  }
  return res;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout<<dfs(0,1)<<endl;

  return 0;
}
