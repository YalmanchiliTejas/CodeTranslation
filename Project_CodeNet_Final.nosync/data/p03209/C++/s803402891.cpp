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
#define N 200000

long long si[51];
long long p[51];

long long solve(int k, long long x){
	if (x <= 0)return 0;
	if (k == 0)return 1;
	long long re = 0;
	if (x <= 1)return 0;
	if (x >= si[k])return p[k];
	if (x <= si[k - 1] + 1){
		return solve(k - 1, x - 1);
	}
	re = p[k - 1] + 1;
	return re += solve(k - 1, x - si[k - 1] - 2);
}


int main(){
	int n;
	long long k, ans;
	si[0] = 1;
	f(i, 50)si[i + 1] = (si[i] * 2) + 3;
	p[0] = 1;
	f(i, 50)p[i + 1] = (p[i] * 2) + 1;
	scanf("%d %lld", &n, &k);
	ans = solve(n, k);


	printf("%lld\n", ans);


	return 0;
}
