#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int a[3008];
long long dp[3008][3008];

long long solve(int s, int e) {
    if(s==e) {
        return a[s];
    }
    if(!dp[s][e]) {
        dp[s][e] = 0x8000000000000000ll ^ max(a[s]-solve(s+1, e), a[e]-solve(s, e-1));
    }
    return dp[s][e] ^ 0x8000000000000000ll;
}

int main() {
	scanf("%d", &N);
    for(int n=0; n<N; ++n) {
        scanf("%d", &a[n]);
    }
    printf("%lld\n", solve(0, N-1));
	return 0;
}
