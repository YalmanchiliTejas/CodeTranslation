#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct h{
	int a,pos;
}x[N];
bool operator <(h w,h u){
	return w.a<u.a;
}
int ans[N];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i].a);
		x[i].pos=i;
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n/2;i++){
		ans[x[i].pos]=x[n/2+1].a;
	}
	for(int i=n/2+1;i<=n;i++){
		ans[x[i].pos]=x[n/2].a;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}