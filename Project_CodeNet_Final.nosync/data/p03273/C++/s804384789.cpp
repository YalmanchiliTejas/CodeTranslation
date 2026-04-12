#include<iostream>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  char a[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  int ah[h], aw[w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if (a[i][j] != '.'){
	ah[i] = 0;
	break;
      }
      else if(j == w-1) ah[i] = 1;
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if (a[i][j] != '.') {
	aw[j] = 0;
	break;
      }
      else if(i == h-1) aw[j] = 1;
    }
  }

  for(int i=0;i<h;i++){
    if(ah[i] == 0){
      for(int j=0;j<w;j++){
	if(aw[j] == 0){
	  cout << a[i][j];
	}
      }
      cout << endl;
    }
  }
}
