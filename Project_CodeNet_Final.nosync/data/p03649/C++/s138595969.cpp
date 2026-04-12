#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 55;

int N; ll Nr[MAX_N];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%lld", &Nr[i]);
	ll ans = 0;
	int cnt = 0;
	do{
		bool isOK = true;
		ll plus = 0;
		for(int i=0; i<N; i++) if(Nr[i] + plus >= N) {
			isOK = false;
			ll val = (Nr[i] + plus) / N;
			Nr[i] -= val * (N+1);
			plus += val;
			ans += val;
		}
		for(int i=0; i<N; i++) Nr[i] += plus;
		if(isOK) break;
	}while(true);
	printf("%lld\n", ans);
	return 0;
}
