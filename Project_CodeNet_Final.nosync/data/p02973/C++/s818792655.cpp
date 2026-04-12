#include<bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
const int N = 2e5 +11;
int a[N],b[N],n;
int t[N],l[N];
int g(int k){
	int ans=0;
	for(;k;k-=k&-k)ans=max(ans,t[k]);
	return ans;
}
void up(int k,int p){
	for(;k<N;k+=k&-k)t[k]=max(t[k],p);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+1+len,a[i])-b,a[i]=n-a[i]+1;
	int ans=0;
	for(int i=1;i<=n;i++){
		l[i]=g(a[i])+1;
		up(a[i],l[i]);
		ans=max(ans,l[i]);
	}
	cout<<ans<<endl;
	return 0;
}