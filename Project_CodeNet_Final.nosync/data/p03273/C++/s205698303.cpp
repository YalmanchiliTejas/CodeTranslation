#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  // 取り込む
  for (int i = 0; i < H; i++) {
  	for (int j = 0; j < W; j++) {
  		cin >> a.at(i).at(j);	
  	}
  }
  // 横チェック
  vector<int> B;
  for (int i=0; i<H; i++) {
  	int cnt = 0;
  	for (int j=0; j<W; j++) {
  			if (a.at(i).at(j) == '#') {
  				cnt++;
  			}
  	}
  	if(cnt > 0) {
  		B.push_back(i);
  	}
  }
  // 横削除
  vector<vector<char>> A(B.size(),vector<char>(W));
  for (int i=0; i<B.size(); i++) {
  	for (int j=0; j<W; j++) {
  		A.at(i).at(j) = a.at(B.at(i)).at(j);
  	}
  }
  // 縦チェック
  vector<int> C;
  for (int j=0; j<W; j++) {
  	int cnt = 0;
  	for (int i=0; i<B.size(); i++) {
  			if (A.at(i).at(j) == '#') {
  				cnt++;
  			}
  	}
  	if(cnt > 0) {
  		C.push_back(j);
  	}
  }
  // 縦削除
  vector<vector<char>> D(B.size(),vector<char>(C.size()));
  for (int j=0; j<C.size(); j++) {
  	for (int i=0; i<B.size(); i++) {
  		D.at(i).at(j) = A.at(i).at(C.at(j));
  	}
  }
  // 表にする
  for (int i=0; i<B.size(); i++) {
  	for (int j=0; j<C.size(); j++) {
  			cout << D.at(i).at(j);
  			if (j == C.size()-1) {
  				cout << endl;
  			}
  	}
  }
}