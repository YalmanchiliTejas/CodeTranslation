#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;
 
int main() {
  int H,W,count=0;
  cin >> H >> W;
  char A[H+10][W+10];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> A[i][j];
      if(A[i][j]=='#') count+=1;
    }
  }
  if(count==H+W-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}