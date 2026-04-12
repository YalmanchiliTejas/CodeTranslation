#include<map>
#include<queue>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=3100;
int n;
ll a[maxn],mx[maxn][maxn],mn[maxn][maxn]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		mx[i][i]=a[i],mn[i][i]=-a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j+i<=n;j++){
			int x=j,y=j+i;
			mn[x][y]=mx[x][y-1]-a[y];
			mn[x][y]=min(mn[x][y],mx[x+1][y]-a[x]);
			mx[x][y]=mn[x][y-1]+a[y];
			mx[x][y]=max(mx[x][y],mn[x+1][y]+a[x]);
		}
	printf("%lld\n",mx[1][n]);
	return 0;
}
