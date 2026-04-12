#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=110,Mo=1000000007;
int f[N][N],a[N],v[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int Pow(int x,int y) {
    int ret=1;
    while(y) {
	if(y&1) ret=1LL*ret*x%Mo;
	x=1LL*x*x%Mo,y>>=1;
    }
    return ret;
}
int main() {
    int n,k,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=v[i]=gi();
    sort(v+1,v+1+n);
    k=unique(v+1,v+1+n)-v-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(v+1,v+1+k,a[i])-v;
    f[0][0]=1;
    for(int i=1;i<=n;i++) {
	f[i][0]=2LL*f[i-1][0]%Mo;
	for(int j=a[i]+1;j<=a[i-1];j++)
	    f[i][0]=(f[i][0]+2LL*f[i-1][j])%Mo;
	int t=(a[i]<=a[i-1]?1:Pow(2,v[a[i]]-v[a[i-1]]));
	for(int j=min(a[i],a[i-1]);j;j--)
	    f[i][j]=1LL*t*f[i-1][j]%Mo;
	for(int j=a[i-1]+1;j<=a[i];j++) {
	    int t=(j==1?Pow(2,v[j])-2:Pow(2,v[j]-v[j-1]+1)-2);
	    f[i][j]=(f[i][j]+1LL*f[i-1][0]*t%Mo*Pow(2,v[a[i]]-v[j]))%Mo;
	}
    }
    for(int i=0;i<=k;i++) ans=(ans+f[n][i])%Mo;
    cout<<ans;
    return 0;
}