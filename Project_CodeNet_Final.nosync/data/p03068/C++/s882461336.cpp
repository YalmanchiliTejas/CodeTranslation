#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
using namespace std;

long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; }return x; }
long lcm(long x, long y) { return(x / gcd(x, y)) * y; }
void indexsort(long* first, long* last, long* func) { sort(first, last, [&](long a, long b) {return func[a] < func[b]; }); }
//--------------------

int main() {

	long N; cin >> N;
	string S; cin >> S;
	long K; cin >> K;
	char it = S[K - 1];

	for (int i = 0; i <= N - 1; i++) if (S[i] != it) S[i] = '*';

	cout << S << endl;
}