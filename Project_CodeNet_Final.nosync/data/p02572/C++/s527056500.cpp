
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
#define pi 3.141592653589793238
#define mod 1000000007
using namespace std;
int main()
{
	cio;
	lli n,i,sum=0,sm2=0;
	cin>>n;
	lli a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		sum%=mod;
	}
	for(i=0;i<n;i++){
		sum=sum-a[i];
		if(sum<0)
		sum+=mod;
		sum%=mod;
		a[i]%=mod;
		sm2+=a[i]*sum;
		sm2%=mod;
	}
	cout<<sm2;
	return 0;
}