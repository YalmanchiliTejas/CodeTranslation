//minamoto
#include<bits/stdc++.h>
#define R register
#define pb push_back
#define fi first
#define se second
#define inline __inline__ __attribute__((always_inline))
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline char getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
int read(){
    R int res,f=1;R char ch;
    while((ch=getc())>'9'||ch<'0')(ch=='-')&&(f=-1);
    for(res=ch-'0';(ch=getc())>='0'&&ch<='9';res=res*10+ch-'0');
    return res*f;
}
const int N=2e5+5;
typedef long long ll;
typedef pair<int,int> pi;
struct node;typedef node* ptr;
inline ll max(R ll x,R ll y){return x>y?x:y;}
struct node{
	ptr lc,rc;ll t,mx;
	inline void upd(){mx=max(lc->mx+t,rc->mx+t);}
}e[N<<2],*rt,*pp=e;
int n,m;vector<pi>pos[N];
void build(ptr &p,int l,int r){
	p=++pp;if(l==r)return;
	int mid=(l+r)>>1;
	build(p->lc,l,mid),build(p->rc,mid+1,r);
}
void update(ptr p,int l,int r,int ql,int qr,int v){
	if(ql<=l&&qr>=r)return p->t+=v,p->mx+=v,void();
	int mid=(l+r)>>1;
	if(ql<=mid)update(p->lc,l,mid,ql,qr,v);
	if(qr>mid)update(p->rc,mid+1,r,ql,qr,v);
	p->upd();
}
void change(ptr p,int l,int r,int x,ll v){
	if(l==r)return p->mx=v,void();
	int mid=(l+r)>>1;
	x<=mid?change(p->lc,l,mid,x,v):change(p->rc,mid+1,r,x,v);
	p->upd();
}
int main(){
//	freopen("testdata.in","r",stdin);
	n=read(),m=read();
	for(R int l,r,x;m;--m)l=read(),r=read(),x=read(),pos[r].pb(pi(l,x));
	build(rt,1,n);
	fp(i,1,n){
		change(rt,1,n,i,rt->mx);
		for(vector<pi>::iterator it=pos[i].begin();it!=pos[i].end();++it)
			update(rt,1,n,it->fi,i,it->se);
	}
	printf("%lld\n",max(rt->mx,0ll));
	return 0;
}