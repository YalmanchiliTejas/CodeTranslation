#include<iostream>

using namespace std;


long long pow(long long a,long long b)
{
  long long ans=1;
  for(int i=1;i<=b;i++)
    ans*=a;
  return ans;
}

long long re(long long n,long long x)
{
  if(n==0)
    return 1;
  if(x==1)
    return 0;
  long long half=pow(2,n+1)-1;
  long long all=pow(2,n+2)-3;
  if(x==half)//half
    return pow(2,n);
  else if(x==all)//all
    return pow(2,n+1)-1;
  else if(x<half)
    return re(n-1,x-1);
  else
    return re(n-1,x-half)+pow(2,n);
}

int main(void)
{
  long long n,x;
  cin >> n >> x;

  cout << re(n,x) << endl;
}