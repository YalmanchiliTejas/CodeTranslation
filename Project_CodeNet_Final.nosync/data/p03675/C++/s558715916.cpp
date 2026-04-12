#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#define lp(n) for (int i = 0; i < n; i++)
#define lop(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define ll long long int
#define sp ' '
#define intmax 2147483647
#define intmin –2147483648
#define llmax 9223372036854775807
#define llmin -9223372036854775808
using namespace std;

int n, a[200000];

int main(){
	cin >> n;
	lp(n)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i -= 2)
		cout << a[i] << sp;
	for (int i = (n % 2 == 0 ? 0 : 1); i < n - 1; i += 2)
		cout << a[i] << sp;
	return 0;
}