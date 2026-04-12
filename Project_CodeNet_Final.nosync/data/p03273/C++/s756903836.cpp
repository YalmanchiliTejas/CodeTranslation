#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> table(H, vector<char>(W));
  int k;
  for (int i = 0; i<H;i++){
    k =0;
    for (int j =0;j<W;j++){
    cin >> table.at(i).at(j);
      if(table.at(i).at(j) == '.') k ++;
      if(k == W) {
        i --;
        H --;
      }  
    }
  }  

  
  for (int j=0;j<W;j++){
    k =0;
    for (int i =0;i<H;i++)
      if(table.at(i).at(j) == '.') k ++;
          
    if(k == H){
      for (int m = j;m<W;m++){
        for(int n = 0;n < H; n++)
         if(m != W-1)  
         table.at(n).at(m) = table.at(n).at(m+1);
      }
      j --;
      W --;
     }
  } 
    
    
 	for (int i=0;i<H;i++){    
    for (int j=0;j<W;j++){
      cout << table.at(i).at(j);
      if (j == W-1) cout << endl;
    }
 	}

}
