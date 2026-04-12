#include <iostream>
#include <vector>
using namespace std;


int main(){
	int H, W;
	char c;
	cin >> H >> W;
	vector<vector<char>> mat(H);
	vector<int> h_cnt(H), w_cnt(W);
	for(int j=0; j<H; j++){
		for(int i=0; i<W; i++){
			cin >> c;
			mat[j].push_back(c);
			if(c=='#'){
				h_cnt[j]++;
				w_cnt[i]++;
			}
		}
	}
	for(int j=0; j<H; j++){
		if(h_cnt[j]!=0){
			for(int i=0; i<W; i++){
				if(w_cnt[i]!=0){
					cout << mat[j][i];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
