#include <bits/stdc++.h>

using namespace std;

int blank_row(vector<vector<char>>& mat){
    for(int i = 0; i < mat.size(); i++){
	bool f = true;
	for(int j = 0; j < mat.at(i).size(); j++){
	    if(mat.at(i).at(j) != '.'){
		f = false;
	    }
	}
	if(f) return i;
    }
    return -1;
}

int blank_col(vector<vector<char>>& mat){
    for(int j = 0; j < mat.at(0).size(); j++){
	bool f = true;
	for(int i = 0; i < mat.size(); i++){
	    if(mat.at(i).at(j) != '.' && mat.at(i).at(j) != '*'){
		f = false;
	    }
	}
	if(f) return j;
    }
    return -1;
}

int main()
{

    int H, W;

    cin >> H >> W;

    vector<vector<char>> mat(H, vector<char>(W));

    for(int i = 0; i < H; i++){
	for(int j = 0; j < W; j++){
	    cin >> mat.at(i).at(j);
	}
    }

    int r;
    while((r = blank_row(mat)) >= 0){
	for(int i = 0; i < mat.at(r).size(); i++){
	    mat.at(r).at(i) = '*';
	}
    }
    while((r = blank_col(mat)) >= 0){
	for(int i = 0; i < mat.size(); i++){
	    mat.at(i).at(r) = '+';
	}
    }
    for(int i = 0; i < H; i++){
	bool f = false;
	for(int j = 0; j < W; j++){
	    if(mat.at(i).at(j) != '*' && mat.at(i).at(j) != '+'){
		f = true;
		cout << mat.at(i).at(j);
	    }
	}
	if(f) cout << endl;
    }
}
