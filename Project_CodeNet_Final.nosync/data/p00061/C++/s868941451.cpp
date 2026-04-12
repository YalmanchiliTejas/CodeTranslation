#include<iostream>
#include<set>
#include<string>
#include<cstdlib>
using namespace std;
int main() {
	int a, b;
	set<int> c;
	int d[101];
	string f;
	while (cin>>f&&f!="0,0") {
		f += ",";
		string h = "";
		int u = 0;
		for (int i = 0; i < f.length(); i++) {
			if (f[i] == ',') {
				if (u == 0) a = atoi(h.c_str());
				else b = atoi(h.c_str());
				u++;
				h = "";
			}
			else
				h += f[i];
		}
		c.insert(b);
		d[a] = b;
	}
	int k = c.size();
	while (cin >> a){
		b = d[a];
		set<int>::iterator it = c.end();
		it--;
		int sum = 0;
		for (int j = 0; j < k; j++) {
			sum++;
			if ((*it) == b) {
				cout << sum << endl;
				break;
			}
			it--;
		}
	}
}