#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define rep2(x,from,to) for(int x=from;x<to;x++)
#define rep(x,to) rep2(x,0,to)
int a[200005];
int p;
int b[200005];
int main()
{
  int n;
  cin>>n;
  rep(i,n)
    {
      cin>>a[i];b[i]=a[i];
    }
  sort(a,a+n);
  p=a[n/2];
  rep(i,n)
    {
      if(b[i]<p)cout<<p<<endl;
      else cout<<a[n/2-1]<<endl;
    }
  return 0;
}