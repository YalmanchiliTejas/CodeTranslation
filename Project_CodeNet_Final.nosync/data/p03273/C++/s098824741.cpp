#include <bits/stdc++.h>

using namespace std;

bool check(vector < string > &v, int &h, int &w, int &i, int &j){
	bool one = true, two = true;
	for(int k = 0; k < w; k++)
		if(v[i][k] == '#'){
			one = false;
			break;
		}
	for(int k = 0; k < h; k++)
		if(v[k][j] == '#'){
			two = false;
			break;
		}
	return one || two;
}

bool check_ans(vector < string > &v, int &h, int &w, int &i){
	for(int j = 0; j < h; j++)
		if(v[j][i] == '#')
			return false;
	return true;
}

int main(){
	int h, w, i, j;
	cin >> h >> w;
	vector < string > v(h);
	vector < pair < int, int > > ans;
	for(i = 0; i < h; i++)
		cin >> v[i];
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(!check(v, h, w, i, j))
				ans.push_back({i,j});
		}
	}
	bool p;
	for(i = 0; i < h; i++){
		p = false;
		for(j = 0; j < w; j++){
			for(int k = 0; k < ans.size(); k++){
				if(ans[k].first == i && ans[k].second == j){
					cout << v[i][j];
					p = true;
					break;
				}
			}
		}
		if(p)
			cout << "\n";
	}		   
    return 0;
}