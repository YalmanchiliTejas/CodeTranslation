
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>


typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBAC
/*map<Keyの型, Valueの型> 変数名;
queue<型> 変数名;
priority_queue<型> 変数名;
priority_queue<型, vector<型>, greater<型>> 変数名;*/
//copy(v1.begin(), v1.end(), back_inserter(v2));
using namespace std;

int gcd(int a, int b) {
	int c;
	if (a < b) {
		c = a; a = b; b = c;
	}
	while (b != 0) {
		c = a % b; a = b; b = c;
	}
	return a;
}

int sort_greater(int m,int n) {
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(),greater<int>());
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
		return 0;
}

int bubblesort(int a[], int n) {
	int sw = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 1;
				sw += 1;
			}
		}
	}
	return sw;
}

int a_z()
{
	for (int i = 0; i <= ('Z' - 'A'); i++) {
		cout << (char)('A' + i);
	}
	return 0;
}

int selecttionsort(int a[], int n) {
	int t,sw = 0, minj;
	for (int i = 0; i < n - 1; i++) {
		minj = i;
		for (int j = 0; j < n - 1; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		t = a[i]; a[i] = a[minj]; a[minj] = t;
		if (i != minj) sw += 1;

	}
	return sw;
}

map<string, int> memo;


int main() {
	//sort(a.begin(),a.end());
	int n, m;
	cin >> n >> m;
	if (n == m) cout << "Yes";
	else cout << "No";
	return 0;
}







