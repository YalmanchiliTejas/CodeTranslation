#include <bits/stdc++.h>
using namespace std;
 
int main() {

	int H,W,flgW,flgH,flgEL;
	cin >> H >> W;
	vector<vector<char>> table(H,vector<char> (W));
	for (int i=0; i<H; i++){
		for (int j=0; j<W; j++){
			cin >> table.at(i).at(j);
		}
	}
	for (int i=0; i<H; i++){
		flgEL = 0;
		for (int j=0; j<W; j++){
			flgW = 0;
			flgH = 0;
			for (int k=0; k<W; k++){
				if (table.at(i).at(k) == '#'){
					flgW = 1;
					flgEL = 1;
				}
			}
			
			for (int k=0; k<H; k++){
				if (table.at(k).at(j) == '#'){
					flgH = 1;
				}
			}
			if ((flgW == 1) && (flgH == 1)){
				cout << table.at(i).at(j);
			}				
		}
		if (flgEL == 1){
		cout <<  endl;
		}
	}
}