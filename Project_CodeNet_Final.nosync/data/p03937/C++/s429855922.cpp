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
	 
	long H, W; cin >> H >> W;
	string res = "Impossible";
	long mycount = 0;

	char A[10][10]; for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> A[i][j];

	for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) if (A[i][j] == '#') mycount++;

	if (mycount == H + W - 1) res = "Possible";

	cout << res << endl;
}