#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define MOD 1000000007LL
using namespace std;

long long int inv(long long int x){
	long long int xpow[30], c[30];
	for(int i=0; i<30; i++){
		if(i==0){
			xpow[i]=x;
			c[i]=1;
		}else{
			xpow[i]=xpow[i-1]*xpow[i-1]%MOD;
			c[i]=c[i-1]*2;
		}
	}
	long long int r=MOD-2, xinv=1;
	for(int i=29;i>=0; i--){
		if(r>=c[i]){
			xinv=xinv*xpow[i]%MOD;
		}
		r=r%c[i];
	}
	return xinv;
}

int main()
{
	long long int n, a, b, c, d;
	scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
	long long int ans[1001]={}, ans1[1001]={};
	ans[0]=1, ans1[0]=1;

	long long int f[1001], invf[1001];
	for(long long int i=0; i<=n;i++){
		if(i==0){
			f[i]=1;
		}else{
			f[i]=i*f[i-1]%MOD;
		}
		invf[i]=inv(f[i]);
	}

	long long int s[1001][1001];
	for(long long int x=a; x<=b; x++){
		for(long long int y=c; y<=d && x*y<=n; y++){
			s[x][y]=f[x*y];
			for(int i=1; i<=y; i++){
				s[x][y]=s[x][y]*invf[x]%MOD;
			}
			s[x][y]=s[x][y]*invf[y]%MOD;
		}
	}

	for(long long int y=c; y<=b && b*y<=n; y++){
		ans[b*y]=s[b][y];
		ans1[b*y]=ans[b*y];
	}
  
	for(long long int x=b-1; x>=a; x--){
      for(long long int m=0; m<=n; m++){
        ans1[m]=ans[m];
      }
		for(long long int m=0; m<=n; m++){
          if(ans[m]!=0){
			for(long long int y=c; y<=d && x*y+m<=n; y++){
				ans1[m+x*y]=(ans1[m+x*y]+ans[m]*f[m+x*y]%MOD*invf[m]%MOD*invf[x*y]%MOD*s[x][y]%MOD)%MOD;
			}
          }
		}
      for(long long int m=0; m<=n; m++){
        ans[m]=ans1[m];
      }
		
	}
	printf("%lld\n", ans[n]);
	return 0;
}