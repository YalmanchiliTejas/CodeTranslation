#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    const ll MOD = 1e9 + 7;
	int N;
    ll res = 0, sum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a;
        cin >> a;
        res = ( res + (sum * a) % MOD ) % MOD;
        sum = (sum + a) % MOD;
    }

    cout << res << endl;
	return 0;
}