
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
//vector
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define pp pop_back
//pair
#define pi pair<int ,int >
#define mk make_pair
#define ff first
#define ss second
//set
#define si set<int>
#define sit set<int>::iterator 
using namespace std;
ll mod=1000000007;
int main()
{
	/*
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif
	*/
fast;
ll n;cin>>n;
ll a[n];
ll sum[n];
fr(i,0,n)
{
	cin>>a[i];
	if(i==0) sum[i]=a[i];
	else sum[i]=sum[i-1]+a[i];
}
ll ans=0,k=n-1,j=0;
fr(i,0,n-1)
{
	ans=(ans+(a[i]*((sum[k]-sum[j])%mod)%mod))%mod;
	j++;
}
cout<<ans;
return 0;
}
 
  