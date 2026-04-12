#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<long long> v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
    vector<vector<long long> > v1(n,vector<long long>(n));
    for(int i=0;i<n-1;i++)
    {
        v1[i][i]=v[i];
        v1[i][i+1]=max(v[i]-v[i+1],v[i+1]-v[i]);
    }
    v1[n-1][n-1]=v[n-1];
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            v1[j][j+i]=max(v[j]-v1[j+1][j+i],v[j+i]-v1[j][j+i-1]);
        }
    }
    cout<<v1[0][n-1]<<endl;
  return 0;
}
