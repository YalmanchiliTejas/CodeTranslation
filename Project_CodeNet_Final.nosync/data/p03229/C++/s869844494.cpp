#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	deque<ll>aq;
	for (int i = 0; i < n; i++)aq.push_back(a.at(i));
	//min-start
	ll mi = 0;
	deque<ll>aqmi = aq;
	deque<ll>ami;
	ami.push_back(aqmi.front());
	aqmi.pop_front();
	bool x = true;
	while (aqmi.size() > 0) {
		if (aqmi.size() == 1)break;
		int a;
		if (x) {
			a = aqmi.back();
			ami.push_front(a);
			aqmi.pop_back();
			a = aqmi.back();
			ami.push_back(a);
			aqmi.pop_back();
			x = false;
		}
		else {
			a = aqmi.front();
			ami.push_front(a);
			aqmi.pop_front();
			a = aqmi.front();
			ami.push_back(a);
			aqmi.pop_front();
			x = true;
		}
	}
	if (aqmi.size() == 1) {
		ll a, b,c;
		a = ami.front();
		b = ami.back();
		c = aqmi.front();
		if (abs(a - c) > abs(b - c))ami.push_front(c);
		else ami.push_back(c);
	}
	ll k = ami.front();
	ami.pop_front();
	while (ami.size() > 0) {
		mi += abs(k - ami.front());
		k = ami.front();
		ami.pop_front();
	}
	//max-start
	ll ma = 0;
	deque<ll>aqma = aq;
	deque<ll>ama;
	ama.push_back(aqma.back());
	aqma.pop_back();
	x = true;
	while (aqma.size() > 0) {
		if (aqma.size() == 1)break;
		ll a;
		if (!x) {
			a = aqma.back();
			ama.push_front(a);
			aqma.pop_back();
			a = aqma.back();
			ama.push_back(a);
			aqma.pop_back();
			x = true;
		}
		else {
			a = aqma.front();
			ama.push_front(a);
			aqma.pop_front();
			a = aqma.front();
			ama.push_back(a);
			aqma.pop_front();
			x = false;
		}
	} 
	if (aqma.size() == 1) {
		ll a, b, c;
		a = ama.front();
		b = ama.back();
		c = aqma.front();
		if (abs(a - c) > abs(b - c))ama.push_front(c);
		else ama.push_back(c);
	}
	k = ama.front();
	ama.pop_front();
	while (ama.size() > 0) {
		ma += abs(k - ama.front());
		k = ama.front();
		ama.pop_front();
	}
	cout << max(mi, ma) << endl;
}