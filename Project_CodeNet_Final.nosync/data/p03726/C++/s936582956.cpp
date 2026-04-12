#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 100005;

int n;
vector<int>e[maxn];
bool f[maxn];
bool dfs(int x,int fa) {
  int cnt=0;
  for(int i=0; i<e[x].size(); i++) {
    int v=e[x][i];
    if(v==fa)continue;
    if(!dfs(v,x))return false;
    if(!f[v])cnt++;
  }
  if(cnt==1){
    f[x]=1;
    return true;
  } else {
    if(cnt>1)return false;
    return true;
  }
}

int main() {
 // freopen("in.cpp","r",stdin);
  cin>>n;
  for(int i=1; i<n; i++) {
    int x,y;
    cin>>x>>y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  if(dfs(1,0)&&f[1])cout<<"Second"<<endl;
  else cout<<"First"<<endl;
  return 0;
}
