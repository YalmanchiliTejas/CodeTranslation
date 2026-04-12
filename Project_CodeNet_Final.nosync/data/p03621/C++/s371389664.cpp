#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define poly vector<ll>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
inline ll read(){
	ll x=0;char ch=getchar();bool d=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') d=0;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return d?x:-x;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=10005,mo=998244353;
char a[N],b[N];
int fac[N],inv[N],f[N][N];
int ksm(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mo){
		if(p&1) res=(ll)res*x%mo;
	}
	return res;
}
void init(int n){
	For(i,fac[0]=1,n) fac[i]=(ll)i*fac[i-1]%mo;
	inv[n]=ksm(fac[n],mo-2);
	Rep(i,n-1,0) inv[i]=(ll)(i+1)*inv[i+1]%mo;
}
int C(int n,int m){
	if(n<m||n<0||m<0) return 0;
	return (ll)fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int main(){
	init(N-1);
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),cnt1=0,cnt2=0;
	For(i,1,n){
		if(a[i]=='1'){
			if(b[i]=='0') cnt2++;
			else cnt1++;
		}
	}
	For(i,0,cnt2) f[0][i]=(ll)fac[i]*fac[i]%mo;
	For(i,1,cnt1) For(j,1,cnt2){
		f[i][j]=((ll)f[i-1][j]*i%mo*j%mo+(ll)f[i][j-1]*j%mo*j)%mo;
	}
	int ans=0;
	For(i,0,cnt1){
		ans=(ans+(ll)f[cnt1-i][cnt2]*fac[i]%mo*fac[i]%mo*C(cnt1,i)%mo*C(cnt1+cnt2,i))%mo;
	}
	cout<<ans;
}