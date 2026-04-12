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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,k;ll r;

int main(){
	scanf("%d%d",&n,&k);
	if(k==0){printf("%lld\n",1LL*n*n);return 0;}
	fore(b,k+1,n+1){
		int qq=0;
		while(qq<=n){
			int s=qq+k;
			int e=min(qq+b,n+1);
			r+=max(e-s,0);
			qq+=b;
		}
	}
	printf("%lld\n",r);
	return 0;
}