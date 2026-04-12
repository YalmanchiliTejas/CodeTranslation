#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)return 0;
		int b[100];
		for (int i = 0; i < n; i++)cin >> b[i];
		sort(b, b + n);
		int res = 0;
		for (int i = 1; i < n - 1; i++)res += b[i];
		cout << res/(n-2) << endl;
	}
}
