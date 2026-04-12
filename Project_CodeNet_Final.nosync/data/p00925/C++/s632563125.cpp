#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define size_of(a) (int)a.size()

int calc(vector< int >& s, vector< char >& op) {
	int cur = s[0], j = 1;
	
	for_(i,0,size_of(op)) {
		if (op[i] == '+') cur += s[j++];
		else cur *= s[j++];
	}
	
	return cur;
}

int main() {
	string s; int r;
	cin >> s >> r;
	
	vector< int > s1, s2;;
	vector< char > op1, op2;
	bool mul = false;
	
	for_(i,0,size_of(s)) {
		if (i & 1) {
			if (s[i] == '*') mul = true;
			else op1.push_back(s[i]), mul = false;
			op2.push_back(s[i]);
		} else {
			if (mul) s1[size_of(s1) - 1] *= s[i] - '0';
			else s1.push_back(s[i] - '0');
			s2.push_back(s[i] - '0');
		}
	}
	
	int c1 = calc(s1, op1), c2 = calc(s2, op2);
	bool f1 = (c1 == r), f2 = (c2 == r);
	
	if (f1 && f2) cout << "U" << endl;
	else if (f1) cout << "M" << endl;
	else if (f2) cout << "L" << endl;
	else cout << "I" << endl;
}