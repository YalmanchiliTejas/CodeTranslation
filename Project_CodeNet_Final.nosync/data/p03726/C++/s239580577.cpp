#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector<int> g[100010];
bool used[100010];

int dfs(int now){
    used[now]=true;
    bool leaf=true;
    int white=0,yet=0;
    for(int i=0;i<g[now].size();i++){
        int next=g[now][i];
        if(used[next]) continue;
        leaf=false;
        int z=dfs(next);
        if(z==1) return 1;
        else if(z==0) white++;
        else yet++;
    }

    if(now==0){
        if(yet==1) return 0;
        else return 1;
    }else{
        if(yet>=2) return 1;
        else if(yet==1) return 0;
        else return -1;
    }
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
  }

  if(dfs(0)) cout<<"First"<<endl;
  else cout<<"Second"<<endl;

  return 0;
}
