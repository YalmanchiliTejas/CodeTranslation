#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

const int MAX_N=100005;
int n;
int a[MAX_N];

int main()
{
	while(cin>>n){
		for(int i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		int t=(n+1)/2;
		LL ans=a[t]-a[t+1];
		if(n%2)    ans=max(a[t]*3-a[t+1],a[t]+a[t-1]);
		for(int i=1;i<=t;++i)
			ans-=a[i]*2;
		for(int i=t+1;i<=n;++i)
			ans+=a[i]*2;
		cout<<ans<<endl;
	}
	
	return 0;
}