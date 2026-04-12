#include<cstdio>
#include<algorithm>
#define int long long 
#define mod 1000000007
int a[110],n;
struct node{
	int x,y;
};
int quickpow(int x,int y){
	if(y==0)return 1;
	if(y==1)return x;
	if(y%2==0)return quickpow(x*x%mod,y/2);
	if(y%2==1)return quickpow(x*x%mod,y/2)*x%mod;
}
node calc(int l,int r,int lim){
	int minn=0x3f3f3f3f3f3f3f3f,cnt=0;
	node ans;
	for(int i=l;i<=r;i++)
		if(a[i]<minn)minn=a[i],cnt=1;
		else if(a[i]==minn)cnt++;
	if(cnt==r-l+1){
		ans.x=(quickpow(2,r-l+1)-2+mod)%mod;
		ans.y=quickpow(2,minn-lim-1);
		return ans;
	}
	int s0=1,s1=1,last=0;
	for(int i=l;i<=r+1;i++){
		if(!last&&a[i]>minn)last=i;
		else if(last&&(i==r+1||a[i]==minn)){
			node Ans=calc(last,i-1,minn);
			(s0*=(Ans.x+4*Ans.y%mod)%mod)%=mod;
			(s1*=Ans.y*2%mod)%=mod;
			last=0;
		}
	}
	s0=(s0+mod-s1)%mod;
	ans.x=(s0*quickpow(2,cnt)%mod+s1*(quickpow(2,cnt)-2+mod)%mod)%mod;
	ans.y=s1*quickpow(2,minn-lim-1)%mod;
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==1){
		printf("%lld",quickpow(2,a[1]));
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++)
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			(ans*=quickpow(2,a[i]-std::max(a[i+1],a[i-1])))%=mod;
			a[i]=std::max(a[i+1],a[i-1]);
		}
	node Ans=calc(1,n,0);
	printf("%lld\n",ans*(Ans.x+2*Ans.y%mod)%mod);
}