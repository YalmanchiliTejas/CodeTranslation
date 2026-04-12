//cwystc <--> 陈威宇是天才  --by cwy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<48||ch>57)&&ch!=45)ch=getchar();
	if (ch==45)f=-1,ch=getchar();
	while (ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
	x*=f;
}

//-------------------------------------------------head-------------------------------------------------

#define G 3
#define maxm 205
#define maxn 8192
#define mod 998244353
int f[maxm][maxn],fac[maxn],inv[maxn];
int n,m;
int power(int a,int b,int p){
	int s=1,w=a;
	while (b){
		if (b&1)s=(ll)s*w%p;
		w=(ll)w*w%p;b>>=1;
	}
	return s;
}
int C(int x,int y){
	if (x<y)return 0;return (ll)fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int A[maxn<<1],B[maxn<<1],r[maxn<<1];
void FFT(int*a,int n){
	Rep(i,0,n)if (i<r[i])swap(a[i],a[r[i]]);
	for (int i=1;i<n;i<<=1){
		int wn=power(G,(mod-1)/i/2,mod);
		for (int j=0,del=i<<1;j<n;j+=del){
			int w=1;
			Rep(k,0,i){
				int x=a[j+k],y=(ll)w*a[j+k+i]%mod;
				a[j+k]=(x+y)%mod,a[j+k+i]=(x-y+mod)%mod;
				w=(ll)w*wn%mod;
			}
		}
	}
}
void iFFT(int*a,int n){
	Rep(i,0,n)if (i<r[i])swap(a[i],a[r[i]]);
	for (int i=1;i<n;i<<=1){
		int wn=power(power(G,(mod-1)/i/2,mod),mod-2,mod);
		for (int j=0,del=i<<1;j<n;j+=del){
			int w=1;
			Rep(k,0,i){
				int x=a[j+k],y=(ll)w*a[j+k+i]%mod;
				a[j+k]=(x+y)%mod,a[j+k+i]=(x-y+mod)%mod;
				w=(ll)w*wn%mod;
			}
		}
	}
	int invn=power(n,mod-2,mod);
	Rep(i,0,n)a[i]=(ll)a[i]*invn%mod;
}
int main(){
	read(n);read(m);
	fac[0]=1;Rep(i,1,maxn)fac[i]=(ll)fac[i-1]*i%mod;
	Rep(i,0,maxn)inv[i]=(ll)power(fac[i],mod-2,mod);
	f[0][0]=1;int _n=1,l=0;while (_n<=2*n)_n<<=1,l++;
	Rep(i,0,_n)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	// Rep(i,0,_n)printf("%d ",r[i]);puts("");what_is(_n);
	Rep(i,0,m){
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		rep(j,0,n)A[j]=(ll)f[i][j]*inv[j]%mod;rep(j,1,n)B[j]=inv[j+2];
		// Rep(i,0,_n)printf("%d ",A[i]);puts("");
		// Rep(i,0,_n)printf("%d ",B[i]);puts("");
		FFT(A,_n);FFT(B,_n);Rep(j,0,_n)A[j]=(ll)A[j]*B[j]%mod;iFFT(A,_n);
		// Rep(i,0,_n)printf("%d ",A[i]);puts("");
		rep(j,0,n)f[i+1][j]=((ll)f[i][j]*(C(j+1,2)+1)+(ll)A[j]*fac[j+2])%mod;
		/*
		rep(j,0,n)if (f[i][j]){
			(f[i+1][j]+=(ll)f[i][j]*(C(j+1,2)+1)%mod)%=mod;
			rep(k,1,n-j)(f[i+1][j+k]+=(ll)f[i][j]*C(j+k+2,k+2)%mod)%=mod;
		}*/
	}
	int res=0;
	// rep(i,0,n)if (f[m][i])cerr << m << " " << i << " " << f[m][i] << endl;
	rep(i,0,n)(res+=(ll)f[m][i]*C(n,i)%mod)%=mod;printf("%d\n",res);return 0;
}