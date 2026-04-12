#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define PI  3.14159265358979323846
#define M 1000000009
ll gcd(ll a,ll b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
ll fast(ll n,ll a,ll m)
{
    if(n==0)
        return 1;
    else if(n==1)
        return a;
    else
    {
        ll res=fast(n/2,a,m)%m;
        if(n%2==0)
            return (((res%m)*(res%m))%m);
        else
            return (((((res%m)*a)%m)*res)%m);
    }
}
int main()
{
  int n,m;
  cin>>n>>m;
  if(n==m)
  {
      cout<<"Yes";
  }
  else
  {
      cout<<"No";
  }


}
