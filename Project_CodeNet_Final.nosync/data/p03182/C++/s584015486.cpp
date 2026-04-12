#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
struct SEG{
	ll seg[1<<19],la[1<<19];
	SEG(void){for(int i=0;i<1<<19;i++)seg[i]=0,la[i]=0;}
	void lazy(int l,int r,int k){
		seg[k]+=la[k];
		if(r-l>0){
			la[k*2+1]+=la[k];
			la[k*2+2]+=la[k];
		}
		la[k]=0;
	}
	void add(int a,int b,int l,int r,int k,ll x){
		lazy(l,r,k);
		if(r<a||b<l)return;
		if(a<=l&&r<=b){
			la[k]+=x;
			lazy(l,r,k);
			return;
		}
		add(a,b,l,(l+r-1)/2,k*2+1,x);
		add(a,b,(l+r+1)/2,r,k*2+2,x);
		seg[k]=max(seg[k*2+1],seg[k*2+2]);
	}
	ll que(int a,int b,int l,int r,int k){
		lazy(l,r,k);
		if(r<a||b<l)return -INF;
		if(a<=l&&r<=b)return seg[k];
		return max(que(a,b,l,(l+r-1)/2,k*2+1),que(a,b,(l+r+1)/2,r,k*2+2));
	}
};
struct t{
	ll a,b,c;
	bool operator<(const t &q)const{
		return a<q.a;
	}
};
ll n,m,ans;
vector<t>q;
SEG seg;
int main(void){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++){
		ll l,r,x;
		scanf("%lld%lld%lld",&l,&r,&x);
		q.PB(t{l,l-1,x});
		q.PB(t{r+1,l-1,-x});
	}
	sort(q.begin(),q.end());
	int p=0;
	for(int i=1;i<=n;i++){
		while(p<q.size()&&q[p].a<=i){
			seg.add(0,q[p].b,0,(1<<18)-1,0,q[p].c);
			p++;
		}
		ans=max(ans,seg.que(0,i-1,0,(1<<18)-1,0));
		seg.add(i,i,0,(1<<18)-1,0,seg.que(0,i-1,0,(1<<18)-1,0));
	}
	printf("%lld\n",ans);
}