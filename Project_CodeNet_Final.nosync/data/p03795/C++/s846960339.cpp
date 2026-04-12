#include <iostream>

using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)

int main() {
	int N; cin >> N;

	cout << (N * 800 - N / 15 * 200) << endl;

	return 0;
}