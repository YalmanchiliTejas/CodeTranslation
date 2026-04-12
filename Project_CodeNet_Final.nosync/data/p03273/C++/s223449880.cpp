#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector<char>>vv;
	vector<char>v;
	int H, W;
	cin >> H >> W;
	char tmp_c;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> tmp_c;
			v.push_back(tmp_c);
		}
		vv.push_back(v);
		v.clear();
	}
	int tmp_cnt = 0;
	//yoko
	for (int i = vv.size()-1; i>=0; i--) {
		tmp_cnt = 0;
		for (int j = vv[i].size()-1; j>=0 ; j--) {
			if (vv[i][j] == '.')tmp_cnt++;
		}
		if (tmp_cnt == vv[i].size()) {
			vv.erase(vv.begin() + i);
		}
	}
	//tate
	for (int i = vv[0].size() - 1; i >= 0; i--) {
		tmp_cnt = 0;
		for (int j = vv.size() - 1; j >= 0; j--) {
			if (vv[j][i] == '.')tmp_cnt++;
		}
		if (tmp_cnt == vv.size()) {
			for (int k = 0; k < vv.size(); k++) {
				vv[k].erase(vv[k].begin() + i);
			}
		}
	}

	for (int i = 0; i<vv.size(); i++) {
		for (int j = 0; j<vv[i].size(); j++) {
			cout << vv[i][j];
		}
		cout << endl;
	}
	return 0;
}