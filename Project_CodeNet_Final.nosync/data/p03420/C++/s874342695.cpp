#include<bits/stdc++.h>
using namespace std;

long long N, K;

int main(){
	cin >> N >> K;

	long long ans = 0;
	if(K == 0){
		cout << N * N  << endl;
		return 0;
	}
	for(long long i = K+1; i <= N; i++){
		long long divi = N/i;
		long long rest = N%i;

		ans += divi * (i - K);
		ans += max((long long)0, rest - K + 1);
		//cout << "b=" << i << " num = " << divi * (i - K) << "," << max((long long)0, rest - K)<< endl;
	}
	cout << ans << endl;

}