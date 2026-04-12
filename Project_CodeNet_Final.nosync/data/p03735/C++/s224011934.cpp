#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=200005;
pin a[maxn];
int n;
i64 ans=1ll<<62;
inline void solve1(){
	int mini=1e9,maxi=0;
	rep(i,1,n)mini=min(mini,a[i].w1),mini=min(mini,a[i].w2);
	rep(i,1,n)maxi=max(maxi,a[i].w1),maxi=max(maxi,a[i].w2);
	int prmin=1e9,prmax=0;
	rep(i,1,n+1){
		if(i!=1){
			ans=min(ans,1ll*(maxi-mini)*(max(prmax,a[i].w1)-min(prmin,a[n].w1)));
		}
		prmax=max(prmax,a[i].w2);
		prmin=min(prmin,a[i].w2);
	}
}
inline void solve2(){
	int mini=1e9,maxi=0;
	rep(i,1,n)mini=min(mini,a[i].w1),mini=min(mini,a[i].w2);
	rep(i,1,n)maxi=max(maxi,a[i].w1),maxi=max(maxi,a[i].w2);
	int prmin=1e9,prmax=0;
	rep(i,1,n){
		if(i!=1){
			ans=min(ans,1ll*(maxi-min(prmin,a[n].w1))*(max(prmax,a[i].w1)-mini));
		}
		prmax=max(prmax,a[i].w2);
		prmin=min(prmin,a[i].w2);
	}
	ans=min(ans,1ll*(prmax-prmin)*(a[1].w1-a[n].w1));
}
int main(){
	read(n);
	rep(i,1,n)read(a[i].w1),read(a[i].w2);
	rep(i,1,n)if(a[i].w1<a[i].w2)swap(a[i].w1,a[i].w2);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
	solve1();
	solve2();
	printf("%lld\n",ans);
	return 0;
}
