#include <bits/stdc++.h>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H,vector<char>(W));
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cin >> a.at(i).at(j);
		}
	}
	
	vector<int> row(H);
	vector<int> col(W);
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if( a.at(i).at(j) == '.' ){
				if( j == W-1 ){
					row.at(i) = 1;
				}
			}
			else{
				break;
			}
		}
	}
	for(int j=0; j<W; j++){
		for(int i=0; i<H; i++){
			if( a.at(i).at(j) == '.' ){
				if( i == H-1 ){
					col.at(j) = 1;
				}
			}
			else{
				break;
			}
		}
	}

	for(int i=0; i<H; i++){
		if(row.at(i)==1){
			continue;
		}
		for(int j=0; j<W; j++){
			if(col.at(j)==1){
			}
			else{
				cout << a.at(i).at(j);
			}
			if(j==W-1){
				cout << endl;
			}
		}
	}
}
