#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
  int n,m,ans=0;
  cin>>n>>m;
  vector<vector<int>> edges(n+1,vector<int>(n+1,0));
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    edges.at(a).at(b)++;
    edges.at(b).at(a)++;
  }
  vector<int> vertex={};
  for (int i=1;i<=n;i++){
    vertex.push_back(i);
  }
  do{
    if (vertex.at(0)!=1) continue;
    int tmp=100000;
    for (int i=0;i<n-1;i++){
      int x=vertex.at(i),y=vertex.at(i+1);
      tmp=min(tmp,edges.at(x).at(y));
    }
    ans+=tmp;
  }while(next_permutation(vertex.begin(),vertex.end()));
  cout<<ans<<endl;
}