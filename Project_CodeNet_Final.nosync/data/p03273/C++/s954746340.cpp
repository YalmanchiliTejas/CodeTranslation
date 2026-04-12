#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a;
	for(int i=0;i<H;i++){
		vector<char> IN(W);
		for(int j=0;j<W;j++){
			cin >> IN[j];
		}
		a.push_back(IN);
	}
	int i=0;
	while(i<(int)a.size()){
		int check = 1;
		for(int j=0;j<W;j++){
			if(a[i][j] == '#'){
				check = 0;
				break;
			}
		}
		if(check)a.erase(a.begin() + i);
		else i++;
	}
	i = 0;
	while(i<(int)a[0].size()){
		int check = 1;
		for(int j=0;j<(int)a.size();j++){
			if(a[j][i] == '#'){
				check = 0;
				break;
			}
		}
		if(check){
			for(int j=0;j<(int)a.size();j++){
				a[j].erase(a[j].begin() + i);
			}
		}
		else i++;
	}
	for(i=0;i<(int)a.size();i++){
		for(int j=0;j<(int)a[0].size();j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}