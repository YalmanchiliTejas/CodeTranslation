#include<cstdio>
using namespace std;
typedef long long ll;
ll a[60],div,ans;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	for(int flag=0,p;!flag;){
		if(a[p=1]<n)flag=1;
		for(int i=2;i<=n;++i)
			if(a[i]>a[p]&&a[i]>=n)flag=0,p=i;
		if(!flag){
			ans+=(div=a[p]/n);a[p]%=n;
			for(int i=1;i<=n;++i)
				if(i!=p)a[i]+=div;
		}
	}
	printf("%lld\n",ans);
    return 0;
}