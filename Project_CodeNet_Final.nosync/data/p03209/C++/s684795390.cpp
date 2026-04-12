#include<bits/stdc++.h>
using namespace std;
long long p[51]={1};
long long f[51]={1};
long long patty(int n,long long x )
{
    if(x==0) return 0;
    if(x>=f[n]-1) return p[n];
    if(x>=f[n-1]+2) return (p[n-1]+1+patty(n-1,x-f[n-1]-2));
    if(x>=1) return patty(n-1,x-1); 
}

#define sc second;
#define fr first;
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n; long long x;
   cin>>n>>x;
   for(int i =1;i<51;i++)
   {
     f[i] = 2*f[i-1] + 3;
     p[i] = 2*p[i-1]+1;
   }
   cout<<patty(n,x);
   return 0;
}