#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int n, m;
vector<int> edge[11];

int slv(int now, int f);

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  cout << slv(1, 0) << endl;

  return 0;
}

int slv(int now, int f){
  
  //cout << now << " " << f << endl;

  if(f & (1 << (now-1)))return 0;

  f = f | (1 << (now-1));
  
  if(f == (1 << (n)) - 1){
    return 1;
  }
  
  int ret = 0;
  for(int i=0;i<edge[now].size();i++){
    ret += slv(edge[now][i], f);
  }

  return ret;
}
