#import<iostream>
#define ll long long
int main() {
	ll N, X, p = 0;
	std::cin >> N >> X;
	for (ll i = (ll)(1 << N / 2) * (1 << (N + 3 >> 1));i;i >>= 1, --X) {
      	if (X + 1 >= i) {
			p |= i >> 1;
			X -= i - 2;
		}
	}
	std::cout << p;
	return 0;
}
