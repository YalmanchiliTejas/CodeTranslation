#include <bits/stdc++.h>
using namespace std;
using lint = long;
using ll = long long;
#define rep(i,n) for(lint (i) = 0;(i) < (lint)(n);(i)++)
#define repInRange(i,start,end) for(lint (i) = (start);(i) < (end);++(i))
using lpair = pair<lint,lint>;
using Vecint = vector<lint>;
using Llist = list<lint>;

ll pow(ll k,ll l) {
	ll ret = 1;
	rep(i,l) {
		ret *= k;
	}
	return ret;
}

template <typename T>
T sum(vector<T> vec) {
	ll ret = 0;
	rep(i,vec.size()) {
		ret += vec.at(i);
	}
	return ret;
}

void Main() {
	string s;
	cin >> s;
	if ((s[0] == s[1])&&(s[2] == s[1])&&(s[0] == s[2])) {
		cout << "No" << '\n';
		return;
	}
	cout << "Yes" << '\n';
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	Main();
	return 0;
}