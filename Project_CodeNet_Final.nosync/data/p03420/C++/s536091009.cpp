//Hello Wolrd
//There is Special Pig Jiong in the world. 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f,oo = inf;
const double pi = acos(-1.0);
#define pc putchar
#define RG register
#define gc getchar
inline ll read(){
	RG ll x=0,f=1;RG char c=gc();
	for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
void write(ll x){
	if(x<0)x=-x,pc('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){
	write(x);puts("");
}
const int Mod = 1e9+7;
int Pow(int a,int b){int ans=1;for(;b;b>>=1,a=1ll*a*a%Mod)if(b&1)ans=1ll*ans*a%Mod;return ans;}
#define rd read
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define rep(i,a,b) for(RG int i=(a);i<(b);++i)
#define Rep(i,a,b) for(RG int i=(a);i<=(b);++i)
#define Down(i,a,b) for(RG int i=(a);i>=(b);--i)
#define fin(x) {freopen(#x".in","r",stdin);}
#define fout(x) {freopen(#x".out","w",stdout);}
#define y1 ________y1
#define x first
#define y second

ll n,k,ans;
int main(){
	n = rd(),k = rd();
	if(k==0){
		printf("%lld\n",n*n);
		return 0;
	}
//	printf("%lld %lld\n")
	for(ll b=k+1;b<=n;b++){
		ll Lun = (n+1)/b;//Lun = 2
		ans+=Lun*(b-k);   //1*2 = 2
		ll LL = b*Lun + k;//
		if(LL<=n)ans+=(n-LL+1);    //
//		printf("%lld %lld\n",ans,b);
	}
	printf("%lld\n",ans);
	return 0;
}


/*
934285914
287927211
*/