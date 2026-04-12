#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
	int H,W;
	string s;
	vector<vector<char>> bord;
	cin >> H >> W;

	for(int i=0;i<H;i++){
		vector<char> t;
		cin >> s;
		for(int j=0;j<W;j++){
			t.push_back(s[j]);
		}
		bord.push_back(t);
	}
	//横を消去
	for(int i=H-1;i>=0;i--){
		size_t siro_count = count(bord[i].begin(), bord[i].end(), '.');
		if(siro_count==W){
			bord.erase(bord.begin()+i);
			H=H-1;
		}
	}
	//縦を消去
	for(int i=bord[0].size()-1;i>=0;i--){
		vector<char> t;
		for(int j=0;j<bord.size();j++){
			t.push_back(bord[j][i]);
		}
		size_t siro_count = count(t.begin(), t.end(), '.');
		if(siro_count==H){
			for(int k=0;k<H;k++){
				bord[k].erase(bord[k].begin()+i);
			}
		}
	}

	//出力
	for(int i=0;i<bord.size();i++){
		for(int j=0;j<bord[i].size();j++){
			cout << bord[i][j];
		}
		cout << endl;
	}

}