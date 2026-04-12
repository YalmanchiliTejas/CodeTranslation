#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=302019;
int a[N],f[N][4],sf[N],pr[N];
#undef int
int main()
{
	#define int long long
	int n; cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	pr[1]=a[1]; pr[2]=a[2];
	for(int i=3;i<=n;i++)pr[i]=pr[i-2]+a[i];
	for(int i=1;i<=n;i++)f[i][0]=f[i][1]=f[i][2]=-1e18;
	f[1][0]=a[1]; f[2][0]=a[2];
	for(int i=3;i<=n;i++){
		f[i][1]=max(f[i-2][1]+a[i],pr[i-3]+a[i]);
		f[i][2]=max(f[i-2][2]+a[i],f[i-3][1]+a[i]);
		if(i>3)f[i][2]=max(f[i][2],pr[i-4]+a[i]);
	}
	if(n&1)cout<<max(pr[n]-a[1],max(max(pr[n-2],pr[n-1]),max(f[n][2],max(f[n-1][1],f[n][1]))))<<endl;
	else cout<<max(pr[n],max(pr[n-1],f[n][1]))<<endl;
	return 0;
}