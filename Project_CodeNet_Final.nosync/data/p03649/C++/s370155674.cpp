#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 55
#define MAXK 5
//~ #define MAXK 1000000000000005
#define lint long long
#define trace(x) cout<<#x<<" = "<<x<<'\n'
#define trace2(x, y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<'\n'
#define tracea(arr, i) cout<<#arr<<"["<<i<<"]"<<" = "<<arr[i]<<'\n'
#define print(arr, n) for (int iDx = 0; iDx < (n); iDx++) cout << arr[iDx] << " \n"[iDx == (n)-1]
#define sz(x) (int)(x).size()
using namespace std;
struct ii {
	int a, b;
	bool operator < (ii o) const { return make_tuple(a, b) < make_tuple(o.a, o.b); }
};
struct iii {
	int a, b, c;
	bool operator < (iii o) const { return make_tuple(a, b, c) < make_tuple(o.a, o.b, o.c); }
};
int TC, N, M, Q;

lint arr[MAXN];

int main() {
	#ifdef FAIRUZI10
	freopen("/home/fairuzi/Documents/CP/input.in", "r", stdin);
	#endif
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &arr[i]);
	
	lint ans = 0;
	bool selesai = 0;
	while (!selesai) {
		selesai = 1;
		for (int i = 0; i < N; i++) {
			lint step = arr[i]/N;
			if (step > 0) selesai = 0;
			ans += step;
			arr[i] %= N;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				arr[j] += step;
			}
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}
