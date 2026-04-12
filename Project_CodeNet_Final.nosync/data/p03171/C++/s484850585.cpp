#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;
ll a[3005];
ll f[3005][3005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	fore(l,1,n+1)fore(i,0,n-l+1){
		int j=i+l;
		f[i][j]=max(a[i]-f[i+1][j],a[j-1]-f[i][j-1]);
	}
	printf("%lld\n",f[0][n]);
	return 0;
}