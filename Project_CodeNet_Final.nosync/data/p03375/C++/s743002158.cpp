#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=3005;
inline int ksm(ll a,int b,int mod){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int n,mod,ans;
int s[N][N],ss[N][N],c[N][N];
signed main(){
	n=read(); mod=read();
	s[0][0]=c[0][0]=1; for(int i=0;i<=n;i++)ss[0][i]=1;  
	for(int i=1;i<=n+1;i++){
		s[i][1]=ss[i][1]=1; c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		for(int j=2;j<=n+1;j++)ss[i][j]=(ss[i-1][j]+(s[i][j]=((ll)s[i-1][j]*j+s[i-1][j-1])%mod))%mod;
	}
	for(int i=0;i<=n;i++){
		int sum=0;
		for(int j=0;j<=i;j++){
			int t=(ll)ksm(2,(n-i)*j,mod)*c[n][i]%mod,sss=0;
			//if(i<=10)cout<<i<<" "<<j<<" "<<sss<<" "<<s[i+1][j+1]<<endl;
			sum=(sum+(ll)s[i+1][j+1]*t)%mod;
		}
		sum=(ll)sum*ksm(2,ksm(2,n-i,mod-1),mod)%mod;
		ans=(ans+(i&1?-1:1)*sum)%mod;
		//cout<<i<<" "<<sum<<endl;
	}
	cout<<(ans+mod)%mod<<endl;
}
/*
问题：选出任意个不同的n位2进制数，满足对于任意位数，都至少出现了两个1
容斥，求至少i位最多出现1个1的方案数
即对于其中i位，这些数并没有交集 
对于这i位，可以不选，也可以分配掉
这i位有值中有k个出现1个1，i-k没出现1，的选了j个数 
可以发现答案是c(n,i)*c(i,k)*s(k,j)*(2^((n-i)*j))
但这i位没1的情况呢？
这i位没1有2^(n-i)个数，每个选和不选都可以，直接乘2^(2^(n-i)) 
ss是第二类斯特林数的前缀和 
*/ 