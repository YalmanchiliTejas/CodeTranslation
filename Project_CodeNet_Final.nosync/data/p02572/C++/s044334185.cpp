#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define pb push_back

int gcd(int a,int b)
{
	if(b==0)	return a;
	if(a==0)	return b;
	if(a>=b)	return gcd(b,a%b);
	else	return gcd(a,b%a);
}
int mpower(int a,int b,int m)
{
	if(b==0)	return 1;
	if(b==1)	return a%m;
	int res=1;
	a=a%m;
	while(b){
		if(b&1){
			res=(res*a)%m;
		}
		a=((a%m)*(a%m))%m;
		b>>=1;
	}
	return res;
}
int imod(int a,int m)
{
	if(gcd(a,m)!=1)	return 0;
	return mpower(a,m-2,m);
}


int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0,sum=0,ss=0;
	int M=1000000007;
	for(int i=0;i<n;i++){
		sum+=a[i];
		sum%=M;
		ss+=(a[i]*a[i])%M;
		ss%=M;
	}
	ans=((sum%M)*(sum%M))%M;
	ans-=ss;
	ans%=M;
	ans+=M;
	ans%=M;
	int x=imod(2,M);
	ans=(ans*x)%M;
	cout << ans;


	return 0;
}
