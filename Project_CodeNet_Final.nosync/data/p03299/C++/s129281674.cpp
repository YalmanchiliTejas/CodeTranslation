//minamoto
#include<bits/stdc++.h>
#define R register
#define fi first
#define se second
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int P=1e9+7,inv2=(P+1)>>1;
inline void upd(R int &x,R int y){(x+=y)>=P?x-=P:0;}
inline int inc(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y){
	R int res=1;
	for(;y;y>>=1,x=mul(x,x))(y&1)?res=mul(res,x):0;
	return res;
}
typedef pair<int,int> pi;
const int N=105;
int a[N],n,res;pi p;
pi calc(int l,int r,int x){
	R int mn=1e9,mx=0;
	fp(i,l,r)cmin(mn,a[i]),cmax(mx,a[i]);
	if(mn==mx)return pi(ksm(2,mn-x),ksm(2,r-l+1)-2);
	int f=1,s=1,w=0,np=1,coef=1;
	for(int i=l-1,j=l;i<=r;i=j++){
		while(j<=r&&a[j]!=mn)++j;
		if(i+1<=j-1){
			if(i+1==j-1)coef=mul(coef,ksm(2,a[i+1]-mn)),++w;
			else{
				p=calc(i+1,j-1,mn);
				f=mul(f,p.fi);
//				if(mn-x>1)s=mul(s,inc(p.fi,p.se));
//				else 
				s=mul(s,inc(p.fi,inc(p.fi,p.se)));
//				printf("Calc %d %d %d %d\n",i+1,j-1,p.fi,p.se);
				np=mul(np,p.fi);
			}
		}
		w+=j<=r;
	}
//	printf("%d %d %d %d %d %d %d\n",l,r,f,s,w,np,coef);
	if(w==r-l+1)return pi(mul(ksm(2,mn-x),coef),mul(ksm(2,r-l+1)-2,coef));
	f=mul(f,ksm(2,mn-x)),s=mul(s,ksm(2,w)),np=mul(np,2);
//	if(mn-x==1)
//	np=mul(np,2);
	f=mul(f,coef),s=mul(s,coef),np=mul(np,coef);
//	printf("%d %d %d\n",f,s,np);
	return pi(f,inc(s,P-np));
}
int main(){
//	freopen("testdata.in","r",stdin);
	scanf("%d",&n);
	fp(i,1,n)scanf("%d",&a[i]);
	pi p=calc(1,n,0);
	printf("%d\n",inc(p.fi,p.se));
	return 0;
}