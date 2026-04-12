#include <bits/stdc++.h>
using namespace std;

int main() {
 int H,W;
 cin >> H >> W;
  int cnt = 0;
  int a = H;
  int b = W;
  vector<vector<char>>data(H,vector<char>(W));
  for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
   cin >> data.at(i).at(j);                                                           
   }
  }
    for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
     if(data.at(i).at(j) == '.')
       cnt++;
     if(j == W-1){
     if(cnt == W){
       a--;
     for(int k=0;k<W;k++)
       data.at(i).at(k) = '+';
     }
     cnt = 0;  
     }
   }
  }
   for(int i=0;i<W;i++){
  for(int j=0;j<H;j++){
     if(data.at(j).at(i) == '.'||data.at(j).at(i) == '+')
       cnt++;
     if(j == H-1){
     if(cnt == H){
       b--;
     for(int k=0;k<H;k++)
       data.at(k).at(i) = '+';
     }
     cnt = 0;  
     }
   }
  }
  int c = 0,d = 0;
  for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
  if(data.at(i).at(j) != '+'){
    c++;
    if(c == b){
    cout << data.at(i).at(j) << endl;
    c = 0;
    }
    else
    cout << data.at(i).at(j);
  }
  }
  } 
}