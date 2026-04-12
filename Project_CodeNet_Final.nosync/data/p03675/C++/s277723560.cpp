#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 200005;

int n;
int a[MAXN];
deque <int> q;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (i&1) q.push_front(a[i]); else q.push_back(a[i]);
	}
	if (n%2==0) {
		for (int i=0; i<n; i++) {
			cout << q.front() << " ";
			q.pop_front();
		}
	} else {
		for (int i=0; i<n; i++) {
			cout << q.back() << " ";
			q.pop_back();
		}
	}
	return 0;
}