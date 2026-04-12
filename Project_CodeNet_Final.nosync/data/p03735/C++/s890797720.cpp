#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
#include<cstdlib>
#include<cmath>
#define range(i,a,b) for(int i = (a); i <= (b); i++)
#define rrange(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,b) for(int i = 1; i <= (b); i++)
#define rrep(i,b) for(int i = (b); i >= 1; i--)
#define all(a) (a).begin(), (a).end()
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long ll;
const int N=2e5+11;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001LL;
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
pair<int,int> a[N];
int n,Max,Min,mx,mn;
ll ans;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int main(){
//	freopen("ex.in","r",stdin);
	n=read();
	mx=-INF;mn=INF;
	rep(i,n){
		a[i].first=read();a[i].second=read();
		if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
		mx=max(mx,a[i].second);
		mn=min(mn,a[i].second);
	}
	sort(a+1,a+1+n);
	ans=(ll)(mx-mn)*(a[n].first-a[1].first);
	Min=Max=a[1].second;
	range(i,2,n){
		ans=min(ans,(ll)(mx-a[1].first)*(max(Max,a[n].first)-min(Min,a[i].first)));
		Min=min(Min,a[i].second);
		Max=max(Max,a[i].second);
	}
	printf("%lld",ans);
	return 0;
}