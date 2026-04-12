#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> mat(h,vector<char>(w));
	vector<int> row(h,0),col(w);
    for(int i = 0; i < h; i++){
		for(int j = 0;j<w;j++){
			cin >> mat[i][j];
			if (mat[i][j] == '#'){
				col[j]++;
				row[i]++;
			}
		}
	}
	for(int i = 0; i<h;i++){
		if(row[i]==0) continue;
		for(int j = 0; j<w;j++){
			if(col[j]!=0) cout << mat[i][j];
		}
		cout << endl;
	}
			
}
