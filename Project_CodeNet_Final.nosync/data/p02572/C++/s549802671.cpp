/*                                  /   \                                                                   (Hello)//JSM//*/      
/*                                 /*****\                                                                              */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K                                                            */
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define PI 3.1415926535897932384626433832795                                               
#define YY cout<<"YES"
#define NN cout<<"NO"
#define Yy cout<<"Yes"
#define Nn cout<<"No"
#define yy cout<<"yes"
#define nn cout<<"no"
#define EE cout<<"\n"
#define ee cout<<"\n"
#define ne cout<<"-1"
#define pb push_back 
#define fi first
#define se second
#define mkp make_pair    
#define mkt make_tuple
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vc vector<char> 
#define vll vector< pair<ll,ll> > 
#define mps map<string ,ll>
#define mpc map<char ,ll>
#define mpl map<ll, ll>
#define pr pair<ll,ll>
ll pd(ll x,ll y){if(x%y==0) return x/y;else return x/y+1;}
ll pow1(ll n,ll p){if(p==0)return 1;ll x=pow1(n, p/2);x=(x%MOD*x%MOD)%MOD;if(p%2==0) return x;else return (x*n)%MOD;}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll tt=1;

//	   cin>>tt;
	      while(tt--)
{
	
	ll ans=0;
	/*
	3
1 2 3*/
ll n,m,j,k,l,i;
cin>>n;
ll a[n],s=0;
fo(i,n)
{
	cin>>a[i];
s+=a[i];
}
fo(i,n)
{
	ans+=(a[i]*((s-a[i])%MOD))%MOD;
	ans%=MOD;
}
if(ans%2==0)
ans/=2;
else
{
	ans+=MOD;
ans/=2;
}
cout<<ans;
ee;
	
	
}
return 0;
}

