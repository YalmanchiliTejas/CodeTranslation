//Bismillahir-Rahmanir-Rahim
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int llu;
#define f1(i,n) for(i=1;i<=n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define Max 100009
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main()
{
     ll n,i,j,m=0,c,T,s=0,r,k=0,p=0,q,x,y,l;
     cin>>n;
     ll a[n];
     f(i,n){
          cin>>a[i];
          s+=a[i];
     }
     f(i,n-1)
     {
         s-=a[i];
         c=((a[i]%mod)*(s%mod))%mod;
         m=((m%mod)+(c%mod))%mod;
     }
     cout<<m<<endl;
}





