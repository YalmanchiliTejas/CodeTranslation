#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
const int MOD = 1e9+7;
const int MAX =  2e5+5;
int N, ans, sum, a[MAX];

int main(int argc, char ** argv) {
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d", a+i);
	rep(i, 0, N) sum = (sum+a[i])%MOD;
	rep(i, 0, N) {
		sum = (sum-a[i]+MOD)%MOD;
		ans = (ans+1LL*sum*a[i])%MOD;
	}
	printf("%d\n", ans);
	return 0;
}
