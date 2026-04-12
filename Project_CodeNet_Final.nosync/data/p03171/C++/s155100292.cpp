#include<bits/stdc++.h>
using namespace std;
long long int memo[3000][3000];
  long long int osec(vector<long long int> &v,int i,int j,long long int sum)
  {
    if(j==i+1)
      return max(v[i],v[j]);
    if(memo[i][j]!=-1)
      return memo[i][j];
    memo[i][j]=max(sum-osec(v,i+1,j,sum-v[i]),sum-osec(v,i,j-1,sum-v[j]));
    return memo[i][j];
  }
long long int strategy(vector<long long int> &v,long long int sum)
{
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v.size();j++)
    {
      memo[i][j]=-1;
    }
  }
  return osec(v,0,v.size()-1,sum);
}
int main()
{
  int n;
  cin>>n;
  vector<long long int> v;
  for(int i=0;i<n;i++)
  {
    long long int a;
    cin>>a;
    v.push_back(a);
  }
  long long int sum=0;
  for(int i=0;i<v.size();i++)
  {
    sum=sum+v[i];
  }
  long long int t=strategy(v,sum);
  cout<<t-(sum-t);
}