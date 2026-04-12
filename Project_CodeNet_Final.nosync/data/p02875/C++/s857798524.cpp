#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MOD 998244353

int main()
{
  long long n;cin>>n;
  long long i;
  vector<long long> rev(n/2,1);
  vector<long long> num(n/2,0);
  long long left=MOD-2;
  for(i=1;i<n/2;i++)
  {
    num.at(i)=i;
  }
  while(left!=0)
  {    
    if(left%2==1)
    {
      for(i=1;i<n/2;i++)
      {
        rev.at(i)=(rev.at(i)*num.at(i))%MOD;
      }
    }
    left/=2;
    for(i=1;i<n/2;i++)
    {
      num.at(i)=(num.at(i)*num.at(i))%MOD;
    }
  }
  long long ans=1;
  long long n3=3;
  left=n;
  while(left!=0)
  {
    if(left%2==1)
    {
      ans=(n3*ans)%MOD;
    }
    left/=2;
    n3=(n3*n3)%MOD;
  }
  long long mina = 1;
  long long minsum = 1;
  for(i=1;i<n/2;i++)
  {
    mina =(mina*((n-i+1)*(rev.at(i)*2)%MOD)%MOD)%MOD;
    minsum=(mina+minsum)%MOD;
  }
  ans=(ans+(MOD-minsum)*2)%MOD;
  cout<<ans<<endl;
}
