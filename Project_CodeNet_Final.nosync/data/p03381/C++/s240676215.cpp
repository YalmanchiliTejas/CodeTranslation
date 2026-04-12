#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int ans;
int a[300000];
int b[300000];

int main() {
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	int key1 = a[n / 2 - 1];
	int key2 = a[n / 2];
	for (int i = 0; i < n; i++) {
		if (b[i] < key2) {
			cout << key2 << endl;
		}
		else cout << key1 << endl;
	}
	return 0;
}