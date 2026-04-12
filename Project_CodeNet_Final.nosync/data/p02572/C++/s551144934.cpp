#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
#define LARGE 1000000007

int main() {
	int n;
	cin >> n;

	ll a[n];
    ll sa=0;
	rep(i, n) {
        ll A=0;
        cin >> A;
        a[i] = A;
        sa += A;
        sa = sa % LARGE;
    }

	ll sum=0;
	for(int i=0; i<n-1; i++) {
        sa -= a[i];
        if(sa < 0) sa += LARGE;
        ll d = (sa * a[i]) % LARGE;
        sum += d;
        sum = sum % LARGE;
	}

	cout << sum << endl;
	return 0;
}
