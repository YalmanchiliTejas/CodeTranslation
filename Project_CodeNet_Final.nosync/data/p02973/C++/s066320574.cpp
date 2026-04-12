#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int nibun(int l, int r, int t);

int main() {
	int n;
	cin >> n;
	int tmp;
	for (int i = 0;i < n;i++) {
		cin >> tmp;
		if (i == 0) {
			v.push_back(tmp);
		}
		else {
			int index = nibun(0, v.size() - 1, tmp);
			if (index == v.size())v.push_back(tmp);
			else v[index] = tmp;
		}
	}
	cout << v.size() << endl;
}

int nibun(int l, int r, int t) {
	if (t <= v[r])return r + 1;
	if (t > v[l])return l;
	if (r - l <= 1)return r;
	int mid = (r + l) / 2;
	if (v[mid] >= t) {
		return nibun(mid, r, t);
	}
	else {
		return nibun(l, mid, t);
	}
}