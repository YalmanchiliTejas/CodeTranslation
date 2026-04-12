#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxn 100010
typedef long long ll;


int n,m,k;


int main()
{
  int a,b,c;
  while(cin>>a>>b>>c)
  {



  int ans=0;
  ans=a*100+b*10+c;
  if(ans%4==0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;


  }



    return 0;
}
