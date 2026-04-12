#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=3010;
int C[N][N],g[N][N];
inline int Pow(int x,int y,int Mo) {
    int ret=1;
    while(y) {
	if(y&1) ret=1LL*ret*x%Mo;
	x=1LL*x*x%Mo,y>>=1;
    }
    return ret;
}
int main() {
    int n,Mo,ans=0;
    cin>>n>>Mo;
    for(int i=0;i<=n;i++)
	for(int j=C[i][0]=1;j<=i;j++)
	    C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mo;
    for(int i=0;i<=n;i++)
	for(int j=g[i][0]=1;j<=i;j++)
	    g[i][j]=(g[i-1][j-1]+1LL*g[i-1][j]*(j+1))%Mo;
    for(int i=0,t=1;i<=n;i++,t=-t) {
	int sum=0;
	for(int j=0,c=1,k=Pow(2,n-i,Mo);j<=i;j++,c=1LL*c*k%Mo)
	    sum=(sum+1LL*g[i][j]*c)%Mo;
	ans=(ans+1LL*t*C[n][i]*sum%Mo*Pow(2,Pow(2,n-i,Mo-1),Mo))%Mo;
    }
    cout<<(ans+Mo)%Mo;
    return 0;
}