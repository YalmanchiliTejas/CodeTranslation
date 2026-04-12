#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int h, w;
char a[100][100];
bool hb[100];
bool wb[100];
int main() {
	cin >> h >> w;
	lp(h) {
		LP(w, j)
			cin >> a[i][j];
	}
	lp(h) {
		hb[i] = false;
		LP(w, j) {
			if (a[i][j] == '#') {
				hb[i] = true;
				break;
			}
		}
	}
	LP(w, j) {
		wb[j] = false;
		lp(h) {
			if (a[i][j] == '#') {
				wb[j] = true;
				break;
			}
		}
	}
	lp(h) {
		if (hb[i]) {
			LP(w, j) {
				if (wb[j])
					cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
