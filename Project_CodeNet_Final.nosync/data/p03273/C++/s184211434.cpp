#include<iostream>
#include<algorithm>
using namespace std;
//白'.',黒'#'
int main(){
  int h, w;
  char a[100][100];
  int check_g[100] = {0},check_r[100] = {0};
  cin >> h >> w;
  
  for(int i=0;i < h;i++){
    for(int j=0;j < w;j++){
      cin >> a[i][j];
      if(a[i][j] == '.'){
        check_g[i]++;
        check_r[j]++; 
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
     if((check_g[i] != w) && (check_r[j] != h)){
       cout << a[i][j];
     }
    }
    if(check_g[i] != w)
      cout << endl;
  }
}
