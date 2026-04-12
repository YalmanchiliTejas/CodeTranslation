#include<iostream>

using namespace std;

typedef long long llint;

const int MAXN = 55;

llint n, sol;
llint l[MAXN], d[MAXN];

void f () {
	llint sum=0;
	for (int i=0; i<n; i++) {
		d[i]=l[i]/n;
		sol+=d[i];
		sum+=d[i];
		l[i]%=n;
	}
	for (int i=0; i<n; i++) {
		l[i]+=sum-d[i];
	}
}

bool ok () {
	for (int i=0; i<n; i++) {
		if (l[i]>=n) return 0;
	}
	return 1;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	while (!ok()) f();
	cout << sol;
	return 0;
}