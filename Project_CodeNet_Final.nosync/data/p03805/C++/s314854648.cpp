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

int n, m;
int cnt;
int a, b;
int g[8][8];
bool ck[8];
bool flag;

int f(int x) {
	ck[x] = true;
	flag = true;
	lp(n) {
		if (ck[i] == false) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cnt++;
		return 0;
	}
	lp(n) {
		if (g[i][x]&&ck[i]==false) {
			f(i);
			ck[i] = false;
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;
	cnt = 0;
	lp(8) {
		ck[i] = false;
		lop(8, j)
			g[i][j] = false;
	}
	lp(m) {
		cin >> a >> b;
		g[a - 1][b - 1] = true;
		g[b - 1][a - 1] = true;
	}
	f(0);
	cout << cnt << endl;
	return 0;
}