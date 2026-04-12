#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
int a[110],n;
struct node{
	int x,y;
};
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;	
}
node calc(int l,int r,int lim){
	int minn=1e18,cnt=0;
	node ans;
	for (int i=l;i<=r;i++)
		if (a[i]<minn)minn=a[i],cnt=1;
		else if (a[i]==minn)cnt++;
	if (cnt==r-l+1){
		ans.x=(ksm(2,r-l+1)-2+M)%M;
		ans.y=ksm(2,minn-lim-1);
		return ans;
	}
	int s0=1,s1=1,last=0;
	for (int i=l;i<=r+1;i++){
		if (!last&&a[i]>minn)last=i;
		else if (last&&(i==r+1||a[i]==minn)){
			node Ans=calc(last,i-1,minn);
			(s0*=(Ans.x+4*Ans.y%M)%M)%=M;
			(s1*=Ans.y*2%M)%=M;
			last=0;
		}
	}
	s0=(s0+M-s1)%M;
	ans.x=(s0*ksm(2,cnt)%M+s1*(ksm(2,cnt)-2+M)%M)%M;
	ans.y=s1*ksm(2,minn-lim-1)%M;
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if (n==1){
		printf("%lld",ksm(2,a[1]));
		return 0;
	}
	int ans=1;
	for (int i=1;i<=n;i++)
		if (a[i]>a[i-1]&&a[i]>a[i+1]){
			(ans*=ksm(2,a[i]-max(a[i+1],a[i-1])))%=M;
			a[i]=max(a[i+1],a[i-1]);
		}
	node Ans=calc(1,n,0);
	printf("%lld\n",ans*(Ans.x+2*Ans.y%M)%M);
}