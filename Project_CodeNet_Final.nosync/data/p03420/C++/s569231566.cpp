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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	long long n, k,ans;
	long long x,y,z;
	ans = 0;
	scanf("%lld %lld", &n,&k);
	if (k == 0){
		ans = n*n;
		printf("%lld\n", ans);
		return 0;
	}
	else{
		for (long long i = 2; i <= n; i++){
			if (i > k){
				x = i;
				y = n / x;
				ans += ((x - k)*y);
				z = n % x;
				if (k <= z){
					ans += (z - k + 1);
				}
			}
		}

		printf("%lld\n", ans);
		return 0;
	}

	return 0;
}