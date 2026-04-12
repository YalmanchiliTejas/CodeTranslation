#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> input(H,vector<char>(W));
  vector<bool> flagH(H,0), flagW(W,0);
  for (int i = 0; i < H; i++) {
  	for(int j=0;j<W;j++){
      cin >> input.at(i).at(j);
      if(input.at(i).at(j)=='#'&&flagH.at(i)==0){
      	flagH.at(i)=1;
	  }
	  if(input.at(i).at(j)=='#'&&flagW.at(j)==0){
	  	flagW.at(j)=1;
	  }
    }
  }

  for (int i=0;i<H;i++){
  	if(flagH.at(i)){
  	  for (int j=0;j<W;j++){
  	    if(flagW.at(j)){
            cout << input.at(i).at(j);
	    }
	  }
	  cout << endl;
    }
  }
  
  return 0;
}
