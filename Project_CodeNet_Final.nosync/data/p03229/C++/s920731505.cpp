#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<long long>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  
  if(n==2)
  {
    cout<<abs(a[0]-a[1])<<endl;
    return 0;
  }
  vector<int>coef1(n);
  vector<int>coef2(n);
  coef1[0]=1;
  coef1[n-1]=(n%2)? 1:-1;
  coef2[0]=-1;
  coef2[n-1]=(n%2)? -1:1;
  for(int i=1;i<(n-1);i++)
  {
    coef1[i]=(i%2==1)? (-2) : 2;
    coef2[i]=(i%2==1)? 2 : (-2);
  }
  
  sort(coef1.begin(),coef1.end());
  sort(coef2.begin(),coef2.end());
  long long ans1=0;
  long long ans2=0;
  for(int i=0;i<n;i++)
  {
    ans1+=(coef1[i]*a[i]);
    ans2+=(coef2[i]*a[i]);
  }
  cout<<max(ans1,ans2)<<endl;
  return 0;
}