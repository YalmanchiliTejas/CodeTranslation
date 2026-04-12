#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

int n;
vector<int> num;
vector<char> op;

int calc1() {
	vector<int> n = num;
	vector<char> o = op;
	for(int i = 0; i < o.size();) {
		if(o[i] == '*') {
			int m = n[i] * n[i + 1];
			n.erase(n.begin() + i);
			n.erase(n.begin() + i);
			n.insert(n.begin() + i, m);
			o.erase(o.begin() + i);
		}
		else {
			i++;
		}
	}
	int sum = 0;
	for(int i = 0; i < n.size(); i++) {
		sum += n[i];
	}
	return sum;
}

int calc2() {
	int s = num[0];
	for(int i = 0; i < op.size(); i++) {
		if(op[i] == '+') s += num[i + 1];
		else s *= num[i + 1];
	}
	return s;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	while(cin >> s) {
		cin >> n;
		num.clear();
		op.clear();
		for(int i = 0; i < s[i]; i++) {
			if(isdigit(s[i])) num.push_back(s[i] - '0');
			else op.push_back(s[i]);
		}

		bool M = calc1() == n, L = calc2() == n;
		//cout << calc1() << " " << calc2() << endl;
		if(M && L) cout << "U" << endl;
		if(M && !L) cout << "M" << endl;
		if(!M && L) cout << "L" << endl;
		if(!M && !L) cout << "I" << endl;
	}
}