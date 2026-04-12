#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M 1000000007
int main()
{

 

  fastio; 

  ll n;
  cin>>n;
  ll a[n];
  for (int i = 0; i < n; ++i)
  {
     cin>>a[i];
  }

  ll prefix[n]={0};
  prefix[0]=a[0];

  for (int i = 1; i < n; ++i)
  {
     prefix[i]=a[i]+prefix[i-1];
  }
  // for (int i = 1; i < n; ++i)
  // {
  //   cout<<prefix[i]<<" ";
  // }
  // co


  ll sum=0;
  for (int i = 0; i <n-1; ++i)
  {

      
     sum+=(a[i])*(prefix[n-1]%M-prefix[i]%M+M);
     sum=sum%M;

     
  }


   cout<<sum;
 
return 0;   
}