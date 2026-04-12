#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;

const int SIZE=2e5+7;
const int Mod=1e9+7;
long long f[SIZE];
long long a[SIZE];
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	REP(i,n)cin>>a[i];
	for(int i=n-1;i>=0;i--)
		f[i]=(f[i+1]+a[i+1])%Mod;
	long long ans=0;
	REP(i,n-1)
		ans=(ans+a[i]*f[i])%Mod;
	cout<<ans<<endl;
	
	return 0;
}
