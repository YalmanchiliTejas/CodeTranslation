#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (50000)
long long p2[30];

void prpo2(void){
	p2[0] = 2;
	f(i, 29)p2[i + 1] = (p2[i] * p2[i]) % MOD;
	return;
}

long long po2(int x){
	long long re = 1;
	f(i,30){
		if (x % 2 == 1)re = (re*p2[i]) % MOD;
		x = x / 2;
	}
	return re;
}

int main(void){
	int n;
	set<int>se;
	vector<int>v;
	int x, y;
	long long cc, dd, aa, bb;
	long long c[110];
	long long d[110];
	int a[110];
	bool u[110];
	f(i, 110){
		u[i] = false;
		c[i] = -1;
	}
	prpo2();
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
		if (se.count(a[i]) == 0){
			v.push_back(a[i]);
			se.insert(a[i]);
		}
	}
	v.push_back(0);
	sort(v.begin(), v.end(), greater<int>());
	f(i, v.size()-1){
		f(j, n){
			if (a[j] >= v[i])u[j] = true;
			else u[j] = false;
		}
		f(j, n){
			if (u[j]){
				cc = 2;
				dd = 1;
				x = j;
				y = j;
				while (u[y]){
					if (c[y] >= 0){
						cc *= c[y];
						cc = cc%MOD;
						aa = ((2 * c[y]) + d[y]) % MOD;
						dd *= aa;
						dd = dd%MOD;
					}
					else if (c[y] == -1){
						dd *= 2;
						dd = dd%MOD;
					}
					y++;
				}
				for (int ii = x; ii < y; ii++)c[ii] = -2;
				dd = (dd - cc + MOD) % MOD;
				c[x] = cc;
				d[x] = dd;
				j = y;
			}
		}
		aa = po2(v[i] - v[i + 1] - 1);
		f(i, n){
			if (c[i] >= 0)c[i] = (c[i] * aa) % MOD;
		}
	}
	aa = (c[0] + d[0]) % MOD;
	printf("%lld\n", aa);


	
	return 0;
}