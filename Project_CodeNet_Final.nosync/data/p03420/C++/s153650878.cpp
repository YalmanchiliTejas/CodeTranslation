#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	ll s=0,N,K;
	cin >> N >> K;

	rep(i,N)
		s += max(0ll,i+1-K)*(N/(i+1))+max(0ll,N%(i+1)-K+1);

	cout << s-((K==0)*N) << endl;
}