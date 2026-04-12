#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  int sum=0;
  vector<vector<char>> grid(H,vector<char>(W));
  vector<int> Hgrid(H);
  vector<int> Wgrid(W);
  for (int i=0;i<H;i++){
  	for (int j=0;j<W;j++){
  		cin >> grid.at(i).at(j);
  	}
  }
  	for(int i=0;i<H;i++){
  		for(int j=0;j<W;j++){
  			if(grid.at(i).at(j)=='#') sum++;
  		}
  		if (sum==0) Hgrid.at(i)=1;
  		sum=0;
  	}
  	for(int j=0;j<W;j++){
  		for(int i=0;i<H;i++){
  			if(grid.at(i).at(j)=='#') sum++;
  		}
  		if (sum==0)Wgrid.at(j)=1;
  		sum=0;
  	}
  	for(int i=0;i<H;i++){
  		for (int j=0;j<W;j++){
  			if(Hgrid.at(i)==0 && Wgrid.at(j)==0){
  				cout << grid.at(i).at(j);
  			}
  		}
      if (Hgrid.at(i)==0) cout << endl;
  	}
  }