#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
int n,ans,sum,Mod,c[3030][3030],f[3030],g[3030][3030];
IN Pow(int x,int y,int p){
	re res=1;
	while(y){
		if(y&1)res=(ll)res*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return res;
}
I add(int &x,int y){(x+=y)>=Mod?x-=Mod:0;}
IN Plus(int x,int y){(x+=y)>=Mod?x-=Mod:0;return x;}
int main(){
	read(n);read(Mod);
	c[0][0]=1;g[0][0]=1;
	F(i,1,n){
		c[i][0]=1;g[i][0]=1;
		F(j,1,i)c[i][j]=Plus(c[i-1][j],c[i-1][j-1]);
		F(j,1,i)g[i][j]=Plus(g[i-1][j-1],(ll)(j+1)*g[i-1][j]%Mod);
	}
	F(i,0,n){
		sum=(ll)c[n][i]*Pow(2,Pow(2,n-i,Mod-1),Mod)%Mod;
		F(j,0,i)add(f[i],(ll)g[i][j]*Pow(2,(ll)(n-i)*j%(Mod-1),Mod)%Mod);
		if(i&1)add(ans,Mod-(ll)sum*f[i]%Mod);else add(ans,(ll)sum*f[i]%Mod);
	}
	printf("%d",ans);
	return 0;
}

