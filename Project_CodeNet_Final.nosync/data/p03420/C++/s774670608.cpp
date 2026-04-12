#include <iostream>
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	long ans=0;
	for(int i=K+1; i<=N; ++i){
	    int mul=N/i;
	    ans += N-(mul*K+max(0, min(K-1, N%i)));
	}
	cout << ans << endl;
	return 0;
}
