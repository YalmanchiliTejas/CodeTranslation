#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
using namespace std;

long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; }return x; }
long lcm(long x, long y) { return(x / gcd(x, y)) * y; }
void indexsort(long* first, long* last ,long* func) { sort(first, last, [&](long a, long b) {return func[a] < func[b]; }); }
//--------------------

int main() {

	long res = 1;
	long N; cin >> N;
	long H[1000]; for (int i = 1; i <= N; i++) cin >> H[i];
	long B = H[1];

	for (int i = 2; i <= N; i++) {

		if (H[i] >= B) { res++; B = H[i]; }

	}

	cout << res << endl;
}