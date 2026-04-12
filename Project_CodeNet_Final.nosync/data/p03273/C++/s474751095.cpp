#include <iostream>
using namespace std;

int main(){
  int H;
  int W;
  cin >> H;
  cin >> W;
  char c[H][W];
  int a[H]={};
  int b[W]={};

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> c[i][j];
       if(c[i][j]=='.'){
         a[i]++;
         b[j]++;
        }
      }
  }

  for(int i=0;i<H;i++){
    while(a[i]==W && i<H){
      i++;
      }
      if(i==H){
        break;
      }
    for(int j=0;j<W;j++){
      while(b[j]==H && j<W){
        j++;
      }
      if(j==W){
        break;
      }
      
      cout <<c[i][j];
      
    }
  cout << '\n';
  }
  
  return 0;
}
   
