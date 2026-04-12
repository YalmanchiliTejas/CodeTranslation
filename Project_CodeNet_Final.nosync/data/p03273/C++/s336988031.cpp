#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> removeWhite(const vector<string>& v) {
	vector<string> out;
	auto itr = v.begin();
	for (itr; itr != v.end(); ++itr) {
		if (count(itr->begin(), itr->end(), '.') != itr->size()) out.push_back(*itr);
	}
	return out;
}

vector<string> transpose(const vector<string>& v) {
	size_t t_h = v[0].size();
	vector<string> out(t_h);
	auto itr = v.begin();
	for (itr; itr != v.end(); ++itr) {
		int tmp = 0;
		auto itr2 = itr->begin();
		for (itr2; itr2 != itr->end(); ++itr2) {
			out[tmp] += *itr2;
			tmp +=1;
		}
	}
	return out;
}


int main() {
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	for (int i = 0; i < h; ++i) {
		cin >> v[i];
	}
	vector<string> v_r_r= removeWhite(v);
	vector<string> v_r_r_rot = transpose(v_r_r);
	vector<string> v_rc_r = removeWhite(v_r_r_rot);
	vector<string> v_out = transpose(v_rc_r);
	
	auto itr2 = v_out.begin();
	for (itr2; itr2 != v_out.end(); ++itr2) {
		cout << *itr2 << endl;
	}
	return 0;
}