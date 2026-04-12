#include<bits/stdc++.h>
using namespace std;
int a[200009],b[200009];
struct P{
	int a,b;
	inline bool operator<(P x)const{return a<x.a;}
}c[200009];
int main(){
	int n,i,j,x=2e9,y=0,z=2e9,w=0,ans2=2e9;
	long long ans1;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&c[i].a,&c[i].b);
		if(c[i].a>c[i].b)j=c[i].a,c[i].a=c[i].b,c[i].b=j;
		x=min(x,c[i].a),y=max(y,c[i].b);
		z=min(z,c[i].b),w=max(w,c[i].a);
	}
	ans1=(w-x)*1ll*(y-z),y-=x;
	sort(c+1,c+n+1);
	for(i=1,j=2e9;i<n;++i){
		j=min(c[i].b,j);
		w=max(w,c[i].b);
		x=min(j,c[i+1].a);
		ans2=min(ans2,w-x);
	}
	printf("%lld\n",min(ans1,ans2*1ll*y));
	return 0;
}