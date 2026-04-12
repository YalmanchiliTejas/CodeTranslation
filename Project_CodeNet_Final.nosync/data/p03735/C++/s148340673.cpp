#include <bits/stdc++.h>
using namespace std;
int n,nmax=0,nmin=1000000009,aax,ain;
struct bagge{int b,r;}bg[200009];
bool cmp(bagge x,bagge y){
	if(x.r<y.r)	return true;
	else if(x.r==y.r&&x.b<y.b)	return true;
	else return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&bg[i].b,&bg[i].r);
		if(bg[i].b<bg[i].r)	swap(bg[i].b,bg[i].r);
	}
	sort(bg+1,bg+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(bg[i].r<=nmin&&bg[i].b>=nmax){
			nmin=bg[i].r;nmax=bg[i].b;
			aax=i;ain=i;
		}
		else if(bg[i].r<nmin){
			nmin=bg[i].r;
			aax=i;
		}
		else if(bg[i].b>nmax){
			nmax=bg[i].b;
			ain=i;
		}
	int bmax=nmax,rmin=nmin,bmin=1000000009,rmax=0;
	for(int i=1;i<=n;i++)	rmax=max(rmax,bg[i].r),bmin=min(bmin,bg[i].b);
	long long ans=(long long)(bmax-bmin)*(rmax-rmin);
	bg[n+1].r=1000000009;
	if(ain!=aax){
		bmin=nmin;bmax=nmax;rmax=max(bg[1].b,bg[n].r);rmin=min(bg[1].b,bg[2].r);
		int premin=bg[1].b;ans=min(ans,(long long)(bmax-bmin)*(rmax-rmin));
		for(int i=2;i<=n;i++){
			rmax=max(rmax,bg[i].b);
			rmin=min(min(premin,bg[i].b),bg[i+1].r);
			premin=min(premin,bg[i].b);
			ans=min(ans,(long long)(bmax-bmin)*(rmax-rmin));
		}
	}
	printf("%lld",ans);
	return 0;
}