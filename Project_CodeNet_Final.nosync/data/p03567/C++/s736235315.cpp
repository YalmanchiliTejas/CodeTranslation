#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL

template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<template<class, class...> class C, class... A>
typename enable_if<!is_same<C<A...>, string>::value, ostream&>::type
operator<<(ostream& os, const C<A...> &c) {
	auto i = c.begin();
	while (i != c.end()) {
		os << " {"[i == c.begin()] << *i;
		os << ",}"[++i == c.end()];
	}
	return os;
}

#define debug(x) cerr << #x << " = " << x << endl;

#else
#define debug(...) {}
#endif

const int N = 1e6 + 5;

#define st first
#define nd second

typedef pair<int,int> pun;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i ++) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}
