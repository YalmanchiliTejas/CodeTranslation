#include<iostream>
#include<vector>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> a(H, vector<char>(W, '.'));
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			cin >> a[i][j];

	vector<char> b(W, '.');
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == b) {
			a.erase(a.begin() + i);
			i--;
		}
	}

	for(int i = 0; i < a[0].size(); i++){
		for(int j = 0; j < a.size(); j++) {
			if(a[j][i] != '.')
				break;
			else if(a[j][i] == '.' && j == a.size()-1){
				for(int k = 0; k < a.size(); k++)
					a[k].erase(a[k].begin() + i);
				i--;
			}
		}
	}

	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < a[0].size(); j++){
			cout << a[i][j];
			if(j == a[0].size() - 1)
				cout << endl;
		}

	return 0;
}