#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 1234567890
using namespace std;
namespace ywy{
	inline int get(){
		int n=0;char c;while((c=getchar())||233333){
			if(c>='0'&&c<='9')break;if(c=='-')goto s;
		}n=c-'0';while((c=getchar())||233333){
			if(c>='0'&&c<='9')n=n*10+c-'0';else return(n);
		}s:while((c=getchar())||23333){
			if(c>='0'&&c<='9')n=n*10-c+'0';else return(n);
		}
	}
	typedef struct _n{
		int a;int b;
		friend bool operator <(const _n &a,const _n &b){
			return(a.a<b.a);
		}
	}node;node memchi[200001];
	void ywymain(){
		int n=get();
		if(n==1){
			cout<<0<<endl;return;
		}
		int mxa=-inf,mxb=-inf,mna=inf,mnb=inf;
		for(register int i=1;i<=n;i++){
			int a=get(),b=get();if(a>b)swap(a,b);memchi[i].a=a;memchi[i].b=b;
			mxa=max(mxa,a);mna=min(mna,a);mxb=max(mxb,b);mnb=min(mnb,b);
		}ll ans=((ll)mxa-(ll)mna)*((ll)mxb-(ll)mnb);mnb=mna;sort(memchi+1,memchi+1+n);
		ll dmn=inf;int mx=-inf,mn=inf;for(register int i=1;i<n;i++){
			mx=max(mx,memchi[i].b);mn=min(mn,memchi[i].b);
			dmn=min(dmn,(ll)max(memchi[n].a,mx)-min(memchi[i+1].a,mn));
		}ans=min(ans,dmn*(mxb-mnb));cout<<ans<<endl;
	}
}
int main(){
	ywy::ywymain();return(0);
}