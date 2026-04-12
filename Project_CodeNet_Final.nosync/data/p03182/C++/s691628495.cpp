#include<cstdio>
#include<algorithm>
#define int long long
const int N=2e5+3,INF=1e18;
struct segment{int l,r,a;}a[N];
bool Cmp(const segment&a,const segment&b){return a.r<b.r;}
int n,m,dp[N],s,ans;
#define M (L+R>>1)
struct segment_tree{
	int mn[1<<19],lz[1<<19];
	inline void Down(int k){
		mn[k<<1]+=lz[k],lz[k<<1]+=lz[k];
		mn[k<<1|1]+=lz[k],lz[k<<1|1]+=lz[k];
		lz[k]=0;
	}
	void Add(int l,int r,int a,int L,int R,int k){
		if(l>r)return;
		if(l<=L&&R<=r){mn[k]+=a,lz[k]+=a;return;}
		Down(k);
		if(l<=M)Add(l,r,a,L,M,k<<1);
		if(r> M)Add(l,r,a,M+1,R,k<<1|1);
		mn[k]=std::min(mn[k<<1],mn[k<<1|1]);
	}
	int Min(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r)return mn[k];
		int res=INF;
		Down(k);
		if(l<=M)res=std::min(res,Min(l,r,L,M,k<<1));
		if(r> M)res=std::min(res,Min(l,r,M+1,R,k<<1|1));
		return res;
	}
}t;
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int j=1;j<=m;j++)
	  scanf("%lld%lld%lld",&a[j].l,&a[j].r,&a[j].a),s+=a[j].a;
	std::sort(a+1,a+1+m,Cmp);
	ans=INF;
	dp[0]=0;
	for(int i=1,j=1;i<=n+1;i++){
	  for(;j<=m&&a[j].r<i;j++)t.Add(0,a[j].l-1,a[j].a,0,n,1);
	  dp[i]=t.Min(0,i-1,0,n,1);
	  t.Add(i,i,dp[i],0,n,1);
	  ans=std::min(ans,dp[i]);
	}printf("%lld",s-ans);
	return 0;
}