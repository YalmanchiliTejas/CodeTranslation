#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int n, a[maxn], b[maxn];
multiset<int> st;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int y = n / 2;
	int x = y - 1;
	for(int i = 0; i < n; i++) {
		if(a[i] <= b[x])
			cout << b[y] << endl;
		else
			cout << b[x] << endl;
	}
	return 0;
}