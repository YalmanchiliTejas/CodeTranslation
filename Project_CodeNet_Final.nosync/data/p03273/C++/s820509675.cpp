#include <iostream>
#include <vector>
#include <string>
using namespace std;

int h, w;
string c[110];
vector<int> wr, wc;
bool f;

int main(){
	cin >> h >> w;
	for (int i = 0; i < h; ++i){
		cin >> c[i];
	}
	for (int i = 0; i < h; ++i){
		f = true;
		for (int j = 0; j < w; ++j){
			if (c[i][j] == '#'){
				f = false;
				break;
			}
		}
		if (!f) wr.push_back(i);
	}
	for (int j = 0; j < w; ++j){
		f = true;
		for (int i = 0; i < h; ++i){
			if (c[i][j] == '#'){
				f = false;
				break;
			}
		}
		if (!f) wc.push_back(j);
	}
	for (auto &i: wr){
		for (auto &j: wc){
			cout << c[i][j];
		}
		cout << endl;
	}
}