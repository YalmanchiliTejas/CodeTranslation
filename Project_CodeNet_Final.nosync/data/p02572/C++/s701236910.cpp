#include<iostream> 
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define Mod 1000000007
using namespace std;
long long ans,n,a[200001],k[200001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i],k[i]=(a[i]+k[i-1])%Mod;
	for(int i=1;i<=n;i++)
		ans=(ans+(k[i-1]*a[i])%Mod)%Mod;
	cout<<ans%Mod; 
}