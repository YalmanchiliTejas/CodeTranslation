#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int qpow(int x,int k,int p){
	int t=1;
	for (;k;k>>=1){
		if (k&1) t=(ll)t*x%p;
		x=(ll)x*x%p;
	}
	return t;
}
int n,p,ans,s[N][N],C[N][N];
void check(int &x,int y){if ((x+=y)>=p) x-=p;}
int main(){
	n=read();p=read();
	s[0][0]=C[0][0]=1;
	for (int i=1;i<=n+1;i++){
		C[i][0]=1;
        for (int j=1;j<=i;j++)
        s[i][j]=(s[i-1][j-1]+(ll)s[i-1][j]*j)%p,
        C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	for (int i=0;i<=n;i++){
		int r=qpow(2,n-i,p),t=1,sum=0;
		for (int j=0;j<=i;j++){
			sum=(sum+(ll)t*s[i+1][j+1])%p;
			t=(ll)t*r%p;
		}
		sum=(ll)sum*C[n][i]%p*qpow(2,qpow(2,n-i,p-1),p)%p;
		check(ans,(i&1) ? (p-sum) : sum);
	}
	printf("%d\n",ans);
	return 0;
}