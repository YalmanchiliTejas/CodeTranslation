#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<list>
using namespace std;

signed main() {
	list<int>L;
	int a; cin >> a;
	for (int b = 0; b < a; b++) {
		int c; cin >> c;
		if ((a+b) & 1)L.push_front(c);
		else L.push_back(c);
	}
	for (auto i = L.begin(); i != L.end(); i++) {
		if (i == --L.end()) { cout << *i << endl; }
		else cout << *i << " ";
	}
}