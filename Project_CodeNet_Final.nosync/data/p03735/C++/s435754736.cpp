#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>-
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define clr(a,x) memset(a,x,sizeof(a))
#define input(x) freopen(x".in","r",stdin)
#define output(x) freopen(x".in"",w",stdout)
#define file(x) input(x),output(x)
using namespace std;

const ll inf=1ll<<60;
const int N=400005,M=100005,mod=1e9+7,INF=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

ll ans;
int n,u[N],v[N];
pii a[N];

int c[N];

ll s1(){
	int b1=0,b2=1e9+7,r1=0,r2=1e9+7;
	for(int i=1;i<=n;i++) gmax(b1,u[i]),gmin(b2,u[i]),gmax(r1,v[i]),gmin(r2,v[i]);
	return (ll)(r1-r2)*(b1-b2);
}
ll s2(){
	int b1=a[1].FF,b2=a[n*2].FF,ans=INF;
	int k=2,cnt=0;
	while(k<n*2){
		if(!c[a[k].SS]) cnt++;
		c[a[k].SS]++;
		if(cnt==n) break;
		k++;
	}
	for(int i=2;i<n*2&&k<n*2;i++){
		gmin(ans,a[k].FF-a[i].FF);
		if(c[a[i].SS]==1) cnt--;
		c[a[i].SS]--;
		while(k<=n*2&&cnt<n){
			if(!c[a[k].SS]) cnt++;
			c[a[k].SS]++;
			if(cnt==n) break;
			k++;
		}
	}//debug(ans);
//	debug(b2-b1);
	return (ll)ans*(b2-b1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&u[i],&v[i]);
		if(u[i]>v[i]) swap(u[i],v[i]);
	}
	for(int i=1;i<=n;i++) a[i]=mp(u[i],i),a[i+n]=mp(v[i],i);
	sort(a+1,a+n*2+1);
//	debug(a[1].FF);
	for(int i=1;i<=n;i++)
		if(u[i]==a[1].FF&&v[i]==a[n*2].FF){
			cout<<s1()<<endl;return 0;
		}
	ans=s1();
//	debug(ans);
	gmin(ans,s2());
	cout<<ans<<endl;
	return 0;
}
