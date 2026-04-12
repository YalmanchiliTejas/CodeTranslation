#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int a;
	bool k = false;
	while (cin >> a&&a != 0) {
		if (k)
			cout << endl;
		string s[10];
		int b[10];
		int g[10];
		bool l[10]; 
		for(int i = 0; i < a; i++) {
			string m;
			int c, d, e;
			cin >> m >> c >> d >> e;
			s[i] = m;
			int f = c * 3 + e;
			b[i] = f;
			g[i] = f;
			l[i] = true;
		}
		sort(g, g + a);
		for (int i = a-1; i >=0; i--) {
			int h = g[i];
			for (int j = 0; j < a; j++) {
				if (b[j] == h&&l[j]) {
					cout << s[j] << "," << h << endl;
					l[j] = false;
					break;
				}
			}
		}
		k = true;
	}
}