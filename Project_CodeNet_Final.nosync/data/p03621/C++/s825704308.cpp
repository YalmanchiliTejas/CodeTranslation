#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=20000+19;
const int p=998244353;
const ll top=1e17;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

char A[N],B[N];
int fac[N],inv[N],val[N];
int l,n,m,c,res;

int C(int n,int m){
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int cal(int n,int m,int k){
	return 1ll*C(m,k)*fac[k]%p*fac[m-k]%p*fac[m-k]%p*C(m+n,m-k)%p;
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	scanf("%s%s",A+1,B+1);
	l=strlen(A+1);
	For(i,1,l+1){
		if (A[i]=='1'&&B[i]=='0') n++;
		if (A[i]=='1'&&B[i]=='1') m++;
	}
	For(i,0,n+1) val[i]=1ll*C(n,i)*Pow(i,n)%p;
	For(k,0,m+1){
		ll tmp=0;
		For(i,0,n+1){
			if (n-i&1) tmp-=val[i];else tmp+=val[i];
			if (tmp<-top||tmp>top) tmp%=p;
		}
		tmp=(tmp%p+p)%p;
		res=(res+1ll*fac[n]*tmp%p*cal(n,m,k))%p;
		For(i,0,n+1) val[i]=1ll*val[i]*i%p;
	}
	printf("%d\n",res);
}