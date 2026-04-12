#include <iostream>
#include <vector>
using namespace std;

int n, a[209]; vector<int>X;

bool isperm() {
	for (int i = 0; i < n; i++) { if (a[i] != i) return false; }
	return true;
}
void shuffle(int p) {
	for (int i = p; i < n; i++) swap(a[i], a[i - p]);
}
bool perm(int p, int q) {
	if (q >= 1 && p < q) return true;
	if (q == 0 && p > q) return true;
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	while (true) {
		if (isperm() == true) break;
		if (perm(a[n - 1], a[0]) == false) { X.push_back(n - 1); shuffle(n - 1); }
		else { X.push_back(1); shuffle(1); }
	}
	cout << X.size() << endl;
	for (int i = 0; i < X.size(); i++)cout << X[i] << endl;
	return 0;
}