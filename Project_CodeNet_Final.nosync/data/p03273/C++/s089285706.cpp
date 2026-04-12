#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	string str;
	getline(cin, str);
	istringstream iss(str);
	iss >> str;
	int H = stoi(str);
	iss >> str;
	int W = stoi(str);
	vector<vector<int>> v;
	v.resize(H);
	for (int i = 0; i < H; i++) {
		v[i].resize(W);
	}

	for (int h = 0; h < H; h++) {
		getline(cin, str);
		for (int w = 0; w < W; w++) {
			string item = str.substr(w, 1);
			if (item == ".") v[h][w] = 0;
			else v[h][w] = 1;
		}
	}

	do {
		int flag = 1;
		vector<int> erase_row;
		int hsize1 = v.size();
		for (int h = 0; h < hsize1; h++) {
			int row_flag = 1;
			int wsize1 = v[0].size();
			for (int w = 0; w < wsize1; w++) {
				if (v[h][w] == 1) {
					row_flag = 0;
					break;
				}
			}
			if (row_flag) {
				erase_row.push_back(h);
			}
		}
		for (int h = erase_row.size() - 1; h >= 0; h--) {
			v.erase(v.begin() + erase_row[h]);
		}
		vector<int> erase_col;
		int wsize2 = v[0].size();
		for (int w = 0; w < wsize2; w++) {
			int col_flag = 1;
			int hsize2 = v.size();
			for (int h = 0; h < hsize2; h++) {
				if (v[h][w] == 1) {
					col_flag = 0;
					break;
				}
			}
			if (col_flag) {
				erase_col.push_back(w);
			}
		}
		for (int i = erase_col.size() - 1; i >= 0; i--) {
			int hsize3 = v.size();
			for (int h = 0; h < hsize3; h++) {
				v[h].erase(v[h].begin() + erase_col[i]);
			}
		}
		if (erase_row.size() == 0 && erase_col.size() == 0) break;
	} while (1);
	int hsize4 = v.size();
	for (int h = 0; h < hsize4; h++) {
		int wsize4 = v[0].size();
		for (int w = 0; w < wsize4; w++) {
			if (v[h][w] == 0) cout << ".";
			else cout << "#";
		}
		cout << endl;
	}
	return 0;
}