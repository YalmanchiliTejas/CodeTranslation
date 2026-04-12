	#include <bits/stdc++.h>

	using namespace std;

	typedef long long ll;

	ll tot = 0;

	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		int N, K;
		cin >> N >> K;
		for (int i = K+1; i <= N; ++i){
			tot += (N - min(K,N%i+1) - (N/(i))*(K));
			if (K > 0) tot++; 	
		}
		cout << tot << '\n';
		cout << flush;
		//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
	}