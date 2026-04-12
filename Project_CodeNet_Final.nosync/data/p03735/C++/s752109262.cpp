#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pa;
#define w1 first
#define w2 second
#define ls (x<<1)
#define rs (x<<1|1)
#define pb push_back
#define mid ((l+r)>>1)
#define SZ(x) ((x).size())
#define All(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
template<class T>void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=1ll*x*x%p)if(k&1)res=1ll*res*x%p;return res;}
const int maxn=2e5+5;
int n;
int minip[maxn],maxip[maxn];
pa w[maxn];
bool cmp(pa a,pa b){return a.w2<b.w2;}
int main(){
	read(n);
	if(n==1)return puts("0"),0;
	rep(i,1,n){
		read(w[i].w1),read(w[i].w2);
		if(w[i].w1>w[i].w2)swap(w[i].w1,w[i].w2);
	}
	sort(w+1,w+n+1);
	int dlt=w[n].w1-w[1].w1;
	sort(w+2,w+n+1,cmp);
	rep(i,1,n)maxip[i]=max(maxip[i-1],w[i].w2);
	minip[0]=1e9+10;rep(i,1,n)minip[i]=min(minip[i-1],w[i].w2);
	ll ans=1ll*dlt*(maxip[n]-minip[n]);
	int mini=w[n].w1,maxi=w[n].w1;
	per(i,n-1,2){
		ans=min(ans,1ll*(w[n].w2-w[1].w1)*(max(maxi,maxip[i])-min(mini,minip[i])));
		mini=min(mini,w[i].w1);
		maxi=max(maxi,w[i].w1);
	}
	mini=min(mini,w[1].w2);
	maxi=max(maxi,w[1].w2);
	ans=min(ans,1ll*(maxi-mini)*(w[n].w2-w[1].w1));
	printf("%lld\n",ans);
	return 0;
}