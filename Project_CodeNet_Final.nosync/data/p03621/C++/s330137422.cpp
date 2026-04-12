///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//                       _oo0oo_                         //
//                      o8888888o                        //
//                      88" . "88      ------ hzt1       //
//                      (| -_- |)                        //
//                      0\  =  /0                        //
//                    ___/`---'\___                      //
//                  .' \|     |// '.                     //
//                 / \|||  :  |||// \                    //
//                / _||||| -:- |||||- \                  //
//               |   | \  -  /// |     |                 //
//               | \_|  ''\---/''  |_/ |                 //
//               \  .-\__  '-'  ___/-. /                 //
//             ___'. .'  /--.--\  `. .'___               //
//          ."" '<  `.___\_<|>_/___.' >' "".             //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |           //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /           //
//     =====`-.____`.___ \_____/___.-`___.-'=====        //
//                       `=---='                         //
//                                                       //
//                                                       //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       //
//                                                       //
//                 God-He Bless All.                     //
//           This Code Will Never Explode.               //
//                                                       //
//                                                       //
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
const int Size=1<<16;
char buffer[Size],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,Size,stdin);
        tail=(head=buffer)+l;
    }
    if(head==tail) return -1;
    return *head++;
}
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=33010;
const int mod=998244353;
int qpow(int n,int m) {
	int ans=1;
	for(;m;m>>=1,n=(ll)n*n%mod) if(m&1) ans=(ll)ans*n%mod;
	return ans;
}
int wn[20],m,e,len;
void NTT(int* A,int len,int tp) {
	int c=1,j=len>>1;
	rep(i,1,len-2) {
		if(i<j) swap(A[i],A[j]);int k=len>>1;
		while(j>=k) j-=k,k>>=1;j+=k;
	}
	for(int i=2;i<=len;i<<=1,c++) {
		for(int j=0;j<len;j+=i) {
			int w=1;
			for(int k=j;k<j+(i>>1);k++) {
				int u=A[k],t=(ll)w*A[k+(i>>1)]%mod;
				A[k]=(u+t)%mod;A[k+(i>>1)]=(u-t+mod)%mod;
				w=(ll)w*wn[c]%mod;
			}
		}
	}
	if(tp<0) {
		int inv=qpow(len,mod-2);
		rep(i,0,len-1) A[i]=(ll)A[i]*inv%mod;
		rep(i,1,len/2-1) swap(A[i],A[len-i]);
	}
}
void mul(int* f,int* g) {
	NTT(f,len,1);NTT(g,len,1);
	rep(i,0,len-1) f[i]=(ll)f[i]*g[i]%mod;
	NTT(f,len,-1);NTT(g,len,-1);
	rep(i,m+1,len-1) f[i]=0;
}
void mul2(int* f) {
	NTT(f,len,1);
	rep(i,0,len-1) f[i]=(ll)f[i]*f[i]%mod;
	NTT(f,len,-1);
	rep(i,m+1,len-1) f[i]=0;
}
int f[maxn],ans[maxn];
void solve(int n) {
	ans[0]=1;
	for(;n;n>>=1,mul2(f)) if(n&1) mul(ans,f);
}
char A[maxn],B[maxn];
int n,fac[maxn],ifac[maxn];
void init() {
	rep(i,1,19) wn[i]=qpow(3,mod-1>>i);
	fac[0]=ifac[0]=ifac[1]=1;
	rep(i,2,n) ifac[i]=(ll)(mod-mod/i)*ifac[mod%i]%mod;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod,ifac[i]=(ll)ifac[i-1]*ifac[i]%mod;
}
int main() {
	scanf("%s%s",A+1,B+1);n=strlen(A+1);
	init();
	rep(i,1,n) if(A[i]=='1') {
		if(B[i]=='1') m++;
		else e++;
	}
	len=1;
	while(len<=m*2) len<<=1;
	rep(i,0,m) f[i]=ifac[i+1];
	solve(e);
	int res=0,tmp=(ll)fac[e]*fac[m]%mod*fac[e+m]%mod;
	rep(j,0,m) (res+=(ll)ans[j]*tmp%mod)%=mod;
	printf("%d\n",res);
	return 0;
}