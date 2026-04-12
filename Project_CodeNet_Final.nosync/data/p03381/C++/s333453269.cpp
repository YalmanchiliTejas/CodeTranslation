/*
ID: kiwio
LANG: C++14
TASK: 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
int n, x[200005], lo, hi, fake[200005];
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(NULL);/*
#ifndef turtle
	ofstream cout (".out");
	ifstream cin (".in");
#endif*/
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x[i];
		fake[i]=x[i];
	}
	sort(fake+1, fake+n+1);
	lo=fake[n/2];
	hi=fake[n/2+1];
	for (int i=1; i<=n; i++) {
		if (x[i]>lo) {
			cout << lo << endl;
		}
		else {
			cout << hi << endl;
		}
	}
 }