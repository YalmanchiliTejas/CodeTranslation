#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	cin>>h>>w;
	vector<string>a(h);
	for (int i=0; i<h; i++){
		cin>>a[i];}

	vector<bool> row(h, false);
	vector<bool> col(w, false);
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++){
			if(a[i][j]=='#'){  // '#'を一つでも含む行列はtrueに設定され、
				row[i] = true; // 下記のコードで出力の対象にされる
				col[j] = true;
			}
		}
	}

	for (int i=0; i<h; i++){
		if (row[i]) {
			for (int j=0; j<w; j++){
				if(col[j]){
					cout<<a[i][j]; // '#'がある行列の中で'#'マスだけ出力する
				}                  // 全て'.'の行列は出力されないことになる
			}
			cout<<endl;  //　改行する
		}
	}
}
