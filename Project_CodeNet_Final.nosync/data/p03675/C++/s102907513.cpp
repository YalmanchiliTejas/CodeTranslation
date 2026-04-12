#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <stdio.h>
#include <cmath>
#include <map>
#include <deque>
using namespace std;

#define MOD 1000000007
#define ll long long int

int main() {
	int n;
	cin >> n;
	deque<int> q;
	bool toend = true;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(toend) {
			q.push_back(a);
		} else {
			q.push_front(a);
		}
		toend = !toend;
	}
	if(n%2 == 0) {
		for(int i = 0; i < n; i++) {
			cout << q.at(i) << " ";
		}
	} else {
		for(int i = 0; i < n; i++) {
			cout << q.at(n-i-1) << " ";
		}
	}
	return 0;
}

