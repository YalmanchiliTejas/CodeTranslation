#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> input(H);
  for(int i=0; i<H; i++){
  	cin >> input[i];
  }
  
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  
  for(int i=0; i<H; i++){
  	for(int j=0; j<W; j++){
    	if(input[i][j] == '#'){
        	row[i] = true;
          	col[j] = true;
        }
    }
  }
  
  for(int i=0; i<H; i++){
  	if(row[i]){
    	for(int j=0; j<W; j++){
        	if(col[j]) cout << input[i][j];
        }
        cout << endl;
    }
  }
  
}