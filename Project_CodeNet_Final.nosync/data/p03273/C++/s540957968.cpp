#include <iostream>
using namespace std;
int main(){
  int h, w, i, j;
  cin >> h >> w;
  char a[h][w];
  for(i=0;i<h; i++)
    for(j=0; j<w; j++)
      cin >> a[i][j];
  
  for(i=0; i<h; i++){
    int flag=0;
    for(j=0; j<w; j++){
      if(a[i][j]=='.') flag++;
    }
    if(flag==w){
       for(j=0; j<w; j++){
	 a[i][j]=0;
       }}
  }

  for(j=0; j<w;j++){
    int flag=0;
    for(i=0; i<h; i++){
      if(a[i][j]=='.'||a[i][j]==0) flag++;
    }
    if(flag==h){
      for(i=0;i<h; i++){
	a[i][j]=0;
      }}
  }
  

  for(i=0; i<h; i++){int flag=0;
    for(j=0;j<w;j++){
      if(a[i][j]!=0){cout << a[i][j];
	flag++;
      }
    }if(flag!=0)cout << endl;
  }
      
  return 0;
}