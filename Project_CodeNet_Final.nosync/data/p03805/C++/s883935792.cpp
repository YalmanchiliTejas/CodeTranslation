#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &p,vector<vector<int>> &v)
{
  for(int i=0;i<p.size()-1;i++)
    if(v[p[i]][p[i+1]]==0)
      return false;
 /* for(auto i:p)
    cout<<i<<" ";
  cout<<"\n";  */
  return true;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n,vector<int>(n,0));
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    v[a-1][b-1]=1;
    v[b-1][a-1]=1;
  }
  vector<int> p(n);
  for(int i=0;i<n;i++)
    p[i]=i;
  int ans=0;
  do
  {
    if(p[0]!=0) break;
    if(check(p,v))
      ans++;
  }while(next_permutation(p.begin(),p.end()));
  
  cout<<ans;
  return 0;
}
