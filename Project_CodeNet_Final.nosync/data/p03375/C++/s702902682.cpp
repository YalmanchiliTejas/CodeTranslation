#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=3005;
int mod;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n;
int C[N][N],S[N][N];
int p[N],pp[N];
int main(){
	n=read(),mod=read();
	For(i,0,n)
		C[i][0]=1;
	For(i,1,n)
		For(j,1,i)
			C[i][j]=Add(C[i-1][j]+C[i-1][j-1]);
	S[0][0]=1;
	For(i,1,n)
		For(j,0,i){
			if (j>0)
				S[i][j]=Add(S[i-1][j-1]+(LL)S[i-1][j]*j%mod);
			Add(S[i][j],S[i-1][j]);
		}
//	For(i,0,n){outarr(S[i],0,n)}
	For(i,0,n){
		p[i]=Pow(2,i);
		mod--;
		int tmp=Pow(2,i);
		mod++;
		pp[i]=Pow(2,tmp);
	}
	int ans=0;
	For(i,0,n)
		For(j,0,i){
			int v=(LL)S[i][j]*pp[n-i]%mod*Pow(p[n-i],j)%mod*C[n][i]%mod;
//			printf("(%d,%d,%d)\n",i,j,v);
			if (i&1)
				Del(ans,v);
			else
				Add(ans,v);
		}
	cout<<ans<<endl;
	return 0;
}