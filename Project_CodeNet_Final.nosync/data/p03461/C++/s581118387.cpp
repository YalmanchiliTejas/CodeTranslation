#include <bits/stdc++.h>
#define Open(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define rg  register
#define LL long long
using namespace std;
const int MAXN=666;
const int INF=0x3f3f3f3f;
int A,B;
int d[MAXN][MAXN],f[MAXN][MAXN];

template <typename T> inline void in(T &a) {
	T ch = getchar(), f = 1;
	for(a = 0; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
	for( ; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
	a *= f;
}

template <typename T> inline void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
//f[i][j]=max{d[x][y]-i*x-j*y}
//表示从S到T的路径上有i个x和j个y时其余边的最小可能长度
//d[x][y]=min{f[i][j]+i*x+j*y}

signed main(){
	in(A),in(B);
	
	for(rg int i=1;i<=A;i++){
		for(rg int j=1;j<=B;j++)
			scanf("%d",&d[i][j]);
	} 
    
    for(rg int i=0;i<=100;i++){
    	for(rg int j=0;j<=100;j++){
    		for(rg int x=1;x<=A;x++){
				for(rg int y=1;y<=B;y++)
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
			}
		}
	}
	
	int now=INF;
	for(rg int x=1;x<=A;x++){
		for(rg int y=1;y<=B;y++){
			now=INF;
			for(rg int i=0;i<=100;i++){
				for(rg int j=0;j<=100;j++)
					now=min(now,f[i][j]+i*x+j*y);
			}
			if(now!=d[x][y]){
				puts("Impossible");
				return 0;
			}
		}
	}
    puts("Possible");
    puts("202 10401");
    for(rg int i=1;i<=100;i++)
    	printf("%d %d X\n",i,i+1);
    for(rg int i=102;i<=201;i++)
    	printf("%d %d Y\n",i,i+1);
    for(rg int i=0;i<=100;i++){
    	for(rg int j=0;j<=100;j++)
    		printf("%d %d %d\n",i+1,202-j,f[i][j]);
	}
	puts("1 202");
	return 0;
}
/*


*/
