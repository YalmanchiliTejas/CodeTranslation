#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  vector<bool> point_x(H,false);
  vector<bool> point_y(H,false);

  for(int i=0; i<H; i++){
    cin >> a[i];
  }

  
  for(int h_i=0; h_i<H; h_i++){
      for(int w_i=0; w_i<W; w_i++){
        if(a[h_i][w_i]=='#'){
          point_x[h_i]=true;
          point_y[w_i]=true;
        }
      }
  }

  for(int x=0; x<H; x++){
    if(point_x[x]){
       for(int y=0; y<W; y++){
         if(point_y[y]){
           cout<<a[x][y];
         }
       }
    
    cout <<endl;
    }
    	
    }
  return 0;
}