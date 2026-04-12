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
vector<int> node[10];  

int slv(int now, int f);

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  cout << slv(1, 2) << endl;

  return 0;
}

int slv(int now, int f){

  if(f == (((1 << n) - 1) << 1)){
    return 1;
  }

  int t = 0;
  for(int i=0;i<node[now].size();i++){

    int next = node[now][i];

    if((f & (1 << next)) != 0){
      continue;
    }

    t += slv(next, (f | (1 << next)));
  } 

  return t;
}
