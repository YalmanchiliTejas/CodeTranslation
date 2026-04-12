#include<bits/stdc++.h>
using namespace std;
int main()
{
  set<pair<int, int> > s;
  vector<int> v;
  int n,m;
  cin>>n>>m;int x,y;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    if(x>y)swap(x,y);
    s.insert({x,y});
  }
  for(int i=2;i<=n;i++)
  {v.push_back(i);}
  int ans=0;
  do
  {
    bool valid=true;
     if(s.count({1,v[0]}))valid=valid & 1;
      else valid=false;
    for(int i=0;i<n-2;i++)
    {
      int u=v[i];int t=v[i+1];
      if(u>t)swap(u,t);
      if(s.count({u,t}))valid=valid & 1;
      else valid=false;
    }
    if(valid){ans++;}
    
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans;
}