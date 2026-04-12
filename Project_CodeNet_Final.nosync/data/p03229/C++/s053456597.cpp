#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define repd(i,j,k) for(int i=j;i>=k;--i)
#define pb push_back
#define db double
#define mp make_pair
#define mp3(a,b,c) mp(a,mp(b,c))
#define pii pair<int,int>
#define fr first
#define se second
#define ll long long 
#define pbc(x) __builtin_popcount(x)
IL int read(){int x;int _w=scanf("%d",&x);return x;}
IL void write(int x){printf("%d\n",x);}
#define int long long
template<typename T>IL void debug(T x){cerr<<x;return;}
const int maxn=1e5+10;
int n,a[maxn];
#undef int
int main(){
#define int long long
	n=read();
	rep(i,1,n)a[i]=read();
	sort(a+1,a+1+n);
	int l=1,r=n,ans=0;
	if(n%2==0){
		int mid=n/2;
		ans-=a[mid];
		repd(i,mid-1,1)ans-=a[i]*2;
		ans+=a[mid+1];
		rep(i,mid+2,n)ans+=a[i]*2;
	}else {
		int ans1=0,ans2=0;
		int mid=n/2+1;
		ans1-=a[mid];ans1-=a[mid-1];
		repd(i,mid-2,1)ans1-=a[i]*2;
		rep(i,mid+1,n)ans1+=a[i]*2;
		ans2+=a[mid];ans2+=a[mid+1];
		rep(i,mid+2,n)ans2+=a[i]*2;
		repd(i,mid-1,1)ans2-=a[i]*2;
		ans=max(ans1,ans2);
	}
	cout<<ans<<endl;
	return 0;
}