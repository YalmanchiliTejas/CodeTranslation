#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
  int W, H;
  cin >> H >> W;
  int a[H][W];

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char ch;
      cin >> ch;
      if(ch=='.') a[i][j] = 0;
      else a[i][j] = 1; 
    }
  }

  bool h_check[H];
  for(int i=0;i<H;i++) h_check[i] = true;

  bool w_check[H];
  for(int j=0;j<W;j++) w_check[j] = true;


  for(int i=0;i<H;i++){
    int check = 0;
    for(int j=0;j<W;j++) check += a[i][j];

    if(check==0) h_check[i]= false;
  }

   for(int j=0;j<W;j++){
    int check = 0;
    for(int i=0;i<H;i++) check += a[i][j];

    if(check==0) w_check[j] = false;
  }


  for(int i=0;i<H;i++){
    if(h_check[i]){
      for(int j=0;j<W;j++){
        if(w_check[j]){
          if(a[i][j]==1) cout << '#';
          else cout << '.';
        }
      }
      cout <<endl;
    }    
  }

  return 0;
}