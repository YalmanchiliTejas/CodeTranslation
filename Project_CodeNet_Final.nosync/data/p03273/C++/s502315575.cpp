#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int h,w;
	cin >> h >> w;
	vector<vector<char>> a(h,vector<char>(w));
	for (int hi=0;hi<h;++hi) {
		for (int wi=0;wi<w;++wi) {
			cin >> a[hi][wi];
		}
	}
	vector<size_t> h_rem;
	for (int hi=0;hi<h;++hi) {
		bool rem = true;
		for (int wi=0;wi<w;++wi) {
			if (a[hi][wi]=='#') {
				rem = false;
				break;
			}
		}
		if (rem) {
			h_rem.push_back(hi);
		}
	}
	int new_h = h - h_rem.size();
	int hosei = 0;
	for (auto rem_i : h_rem) {
		//cout << rem_i << ' ' << hosei << "\n";
		a.erase(a.begin()+rem_i-hosei);
		++hosei;
	}
	vector<size_t> w_rem;
	for (int wi=0;wi<w;++wi) {
		bool rem = true;
		for (int hi=0;hi<new_h;++hi) {
			if (a[hi][wi]=='#') {
				rem = false;
				break;
			}
		}
		if (rem) {
			w_rem.push_back(wi);
		}
	}
	hosei = 0;
	for (auto rem_i : w_rem) {
		//cout << rem_i << ' ' << hosei << "\n";
		for (int i=0;i<a.size();++i) {
			a[i].erase(a[i].begin()+rem_i-hosei);
		}
		++hosei;
	}
	for (int hi=0;hi<a.size();++hi) {
		for (int wi=0;wi<a[hi].size();++wi) {
			cout << a[hi][wi];
		}
		cout << "\n";
	}
	return 0;
}