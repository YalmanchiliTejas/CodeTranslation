#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

signed main(){
	int N, K;
	cin >> N >> K;
	if (K == 0) {
		cout << N * N << endl;
		return 0;
	}
	int res = 0;
	for(int b = K + 1; b <= N; ++b) {
		res += (N+1) / b * (b - K);
		res += max((N + 1) % b - K, 0LL);
	}
	cout << res << endl;
	return 0;
}
