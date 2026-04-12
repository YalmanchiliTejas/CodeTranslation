#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, m;

const int Z = 100;

int me[Z][Z];
int D[11][11];

int main()
{
	read(n, m);
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		int d; read(d);
		D[i][j]=d;
		for(int a=0; a<=Z-1; ++a) for(int b=0; b<=Z-1; ++b){
			me[a][b] = max(me[a][b], d - i*a - j*b);
		}
	}
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		int cd = 1e9;
		for(int a=0; a<=Z-1; ++a) for(int b=0; b<=Z-1; ++b){
			cd = min(cd, me[a][b] + i*a + j*b);
		}
		if(cd != D[i][j]){
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	printf("%d %d\n", Z*2, Z*Z + (Z-1)*2);
	for(int i=2; i<=Z; ++i) printf("%d %d X\n", i-1, i);
	for(int i=Z+1; i<Z*2; ++i) printf("%d %d Y\n", i+1, i);
	for(int a=0; a<=Z-1; ++a) for(int b=0; b<=Z-1; ++b){
		printf("%d %d %d\n", 1+a, Z+1+b, me[a][b]);
	}
	printf("%d %d\n", 1, Z+1);
	return 0;
}
