#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	
	long long int N, mod = 1000000007, ans = 0;
	vector<long long int> A;
	vector<long long int> s;

	cin >> N;

	A.resize(N);
	s.resize(N+1);

	rep(i, N){
		cin >> A[i];
	}

	s[0] = 0;
	rep(i, N){
		s[i+1] = s[i] + A[i];
	}

	rep(i, N){
		ans = (ans + A[i]*((s[N] - s[i+1])%mod) )%mod;
	}

	cout << ans;
 
	return 0;
}