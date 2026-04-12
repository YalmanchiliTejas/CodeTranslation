#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct num {
	int ord; int number;
};
int const MAX = 200003;
num a[MAX];
int b[MAX];
bool order(num x, num y) {
	return x.number < y.number;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i].ord = i;
		cin >> a[i].number;
	}
	sort(a + 1, a + n + 1, order);
	for (int i = 1; i <= n / 2; i++) {
		b[a[i].ord] = n / 2 + 1;
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		b[a[i].ord] = n / 2;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[b[i]].number << endl;
	}
}