#import<cstdio>
#import<algorithm>
using namespace std;
int main(){
	for(int n,m,f,i;scanf("%d%d",&n,&m),n|m;printf("%d\n",f)){
		int a[200010]={0};
		for(i=1;i<=n+m;i++)
			scanf("%d",a+i);
		std::sort(a,a+n+m+1);
		f=0;
		for(i=1;i<=m+n;i++)
			f=std::max(f,a[i]-a[i-1]);
	}
}