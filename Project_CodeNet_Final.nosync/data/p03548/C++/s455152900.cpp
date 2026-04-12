#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#define lp(n) for (int i = 0; i < n; i++)
#define lop(n,i) for (int i = 0; i < n; i++)
#define INT_MAX 2147483647
#define LLINT_MAX 9223372036854775807
#define mod 1000000007
#define ll long long int
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x - z) / (y + z) << endl;
	return 0;
}