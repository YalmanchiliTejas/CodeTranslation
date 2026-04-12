#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;

const int MAX_N=100005;
int n;
int a[MAX_N],d[MAX_N];

int main()
{
	while(cin>>n){
		for(int i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		LL ans=a[n]-a[1]+a[n-1]-a[1];
		int t=n/2;
		for(int i=2,r=n;i<t;r--,++i)
			ans+=a[r]-a[i]+a[r-2]-a[i];
		if(n==3){
			ans=a[3]-a[1]+max(a[3]-a[2],a[2]-a[1]);
		}else	if(n==4){
			ans+=a[n]-a[t];
		}else	if(n>4){
			if(n%2){
				ans+=a[t+3]-a[t];
				ans+=max(a[t+1]-a[t],a[t+2]-a[t+1]);
			}else	ans+=a[t+2]-a[t];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}