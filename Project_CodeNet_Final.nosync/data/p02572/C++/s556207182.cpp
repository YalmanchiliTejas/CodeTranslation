#include<bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define sort(v) sort(v.begin(),v.end()) 
#define pb push_back
/*
ll ar[1000000+9]={0}; 
void seiv() { 
ll n=1000000,i,j; 
ar[1]=1; 
for(i=4;i<=n;i+=2)ar[i]=1; 
for(i=3;i<=n;i+=2) 
{ if(ar[i]==0) 
{ for(j=i*i;j<=n;j+=i*2)ar[j]=1; }
 } 
}*/
int main()
{
  vector<ll>v,x;
 ll a,b,c,d,u,j,k,l,i;
 cin>>a;c=1000000000+7;
 for(i=1;i<=a;i++)
 {
 cin>>b;b=b%c;v.pb(b);x.pb(b);
 if(i>1){x[i-1]=x[i-2]+b;}
 }
   ll sum=0;
for(i=0,j=a-1;i<x.size();i++)
{
 sum+=((x[j]-x[i])%c*v[i]%c)%c;
 sum=sum%c;
}
cout<<sum<<endl;
}