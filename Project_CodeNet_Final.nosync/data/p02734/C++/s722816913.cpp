#include<bits/stdc++.h>
using namespace std;

#define ran 3033

struct modular_arithmetic{
	int mod;

	modular_arithmetic(){
		mod = 998244353;
	}
	//No specific settings.
	int add(int x,int y){return (x+=y)<mod?x:x-mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
};
modular_arithmetic ma;

int n, s;
int a[ran];
int f[ran][ran], g[ran];

int main() {
	scanf("%d%d", &n, &s);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	
	memset(f, 0, sizeof f);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		for(int j=s;j>a[i];j--)
			f[i][j] = ma.add(f[i][j], g[j-a[i]]);
		f[i][a[i]] = i;
		
		ans = ma.add(ans, ma.mul(n-i+1, f[i][s]));
		
		for(int j=0;j<=s;j++)
			g[j] = ma.add(g[j], f[i][j]);
	}
	printf("%d\n", ans);	
	
	return 0;
}