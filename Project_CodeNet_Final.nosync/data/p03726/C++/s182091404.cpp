#include<bits/stdc++.h>
using namespace std;

int n, deg[101000];
vector<int>G[101000];

queue<int>q;

int main(){
  cin.tie(0); int x,y;
  cin>>n;
  for (int i=n-1;i--;){
    cin>>x>>y; ++deg[x]; ++deg[y];
    G[x].push_back(y); G[y].push_back(x);
  }
  for (int i=1;i<=n;++i) if (deg[i]==1) q.push(i);
  
  for (;!q.empty();){
    x=q.front(); deg[x]=0; q.pop();
    for (auto y:G[x])
      if (deg[y]>0){
        deg[y]=0;
        for (auto z:G[y]){
          if (!--deg[z]) return puts("First"), 0;
          if (deg[z]==1) q.push(z);
        }
      }
  }
  puts("Second");
}