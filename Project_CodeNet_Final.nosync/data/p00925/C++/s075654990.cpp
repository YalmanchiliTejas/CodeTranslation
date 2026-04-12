#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector< vector<int> > vvi;

int mf(string s) {
	rep(i, s.length()) {
		if( s[i] == '+' ) {
			return mf(s.substr(0,i)) + mf(s.substr(i+1));
		}
	}
	rep(i, s.length()) {
		if( s[i] == '*' ) {
			return mf(s.substr(0,i)) * mf(s.substr(i+1));
		}
	}
	return atoi(s.c_str());
}

int ltr(string s) {
	for(int i=s.length()-1; i>=0; i--) {
		if( s[i] == '+' ) {
			return ltr(s.substr(0,i)) + ltr(s.substr(i+1));
		}
		else if( s[i] == '*' ) {
			return ltr(s.substr(0,i)) * ltr(s.substr(i+1));
		}
	}
	return atoi(s.c_str());
}

int main() {
	string in;
	cin >> in;
	int ans;
	cin >> ans;
	int m = mf(in);
	int l = ltr(in);
	if( m==ans && l==ans ) {
		cout << "U" << endl;
	} else if( m == ans ) {
		cout << "M" << endl;
	} else if( l == ans ) {
		cout << "L" << endl;
	} else {
		cout << "I" << endl;
	}
	return 0;
}