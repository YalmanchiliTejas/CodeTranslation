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
	int h, w;
	cin >> h >> w;
	char a[9][9];
	lp(h) {
		lop(w, j)
			cin >> a[i][j];
		a[i][w] = '.';
	}
	lp(w + 1)
		a[h][i] = '.';
	int i, j;
	i = j = 0;
	while(true){
		a[i][j] = '.';
		if (a[i + 1][j] == '#')i++;
		else if (a[i][j + 1] == '#')j++;
		else break;
	}
	lp(h + 1)
		lop(w + 1, j) {
			if (a[i][j] == '#') {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	cout << "Possible" << endl;
	return 0;
}