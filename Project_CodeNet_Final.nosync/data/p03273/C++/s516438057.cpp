#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>>a(H ,vector<char>(W));
  for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
		cin >> a.at(i).at(j);
	}
  }
  //行削除
  vector<bool>flg(H);
  for(int i=0;i<H;i++){
	  for(int j=0;j<W;j++){
		  flg.at(i)=false;
		  if (a.at(i).at(j)=='#'){
			  flg.at(i)=true;
			  break;
		  }
	  }
  }
  //列削除
  vector<bool>flg2(W);
  for(int i=0;i<W;i++){
	  for(int j=0;j<H;j++){
		  flg2.at(i)=false;
		  if (a.at(j).at(i)=='#'){
			  flg2.at(i)=true;
			  break;
		  }
	  }
  }
  for(int i=0;i<H;i++){
	if(!flg.at(i))continue;
	for(int j=0;j<W;j++){
		if (flg.at(i)&&flg2.at(j))
		cout<< a.at(i).at(j);
	}
	cout <<endl;
  }
  return(0);
}
