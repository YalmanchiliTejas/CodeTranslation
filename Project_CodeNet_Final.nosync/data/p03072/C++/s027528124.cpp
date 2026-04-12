#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n;
  cin>>n;
  vector<int> v(n);
  for(int &i:v) cin>>i;
  int ans=1;
  for(int i=1;i<n;i++)
  {
    bool flag=true;
    for(int j=0;j<i;j++)
      if(v[j]>v[i])
        flag=false;
    if(flag)
      ans++;
  }
  cout<<ans<<"\n";
  
  
  return 0;
}
