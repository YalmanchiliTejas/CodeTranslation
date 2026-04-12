#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define ll int64_t
const long MOD = 1e9 + 7;

vector<vector<int>> v;
vector<bool> d;
int ans=0;

void dfs(int p){
  d[p]=true;
  bool isallreached=true;
  for (int i = 0; i < d.size(); ++i){
    if (d[i]==false)isallreached=false;
  }
  if (isallreached){
    ans++;
    d[p]=false;
    return;
  }

  for (int i = 0; i < v[p].size(); ++i)
  {
    if (d[v[p][i]] ==false)dfs(v[p][i]);
  }


  d[p]=false;

}

int main()
{
  int n,m;
  cin  >> n >> m;
  v = vector<vector<int>>(n,vector<int>());//頂点aの接続先頂点リスト
  d = vector<bool>(n,false);

  for (int i = 0; i < m; ++i)
  {
    int a,b;
    cin >>a >> b;
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
  }

  dfs(0);


  cout << ans << endl;

  return 0;
}
