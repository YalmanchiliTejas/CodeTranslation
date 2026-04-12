#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using llu = long long unsigned;
using ld = long double;

const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    if(K == 0) return !printf("%lld", N * N);
    for(int i = K + 1; i <= N; i++){
        ans += (N / i) * (i - K) + max(N % i - K + 1, 0LL);
    }
    printf("%lld", ans);    
	return 0;
}