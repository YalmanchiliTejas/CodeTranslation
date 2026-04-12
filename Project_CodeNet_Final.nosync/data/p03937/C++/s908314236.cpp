#include<iostream>
using namespace std;

int main(void){
int h,w;
cin >> h >> w;
char map[8][9];
int vm[8][8];
int sh=0,sw=0;
  
for (int i=0;i<h;i++){
cin >> map[i];
//cout << map[i] << endl;
}
  
for (int i=0;i<h;i++){
for (int j=0;j<w;j++){
	vm[i][j] = map[i][j]=='#'?1:0;
    if (i+j<sh+sw & map[i][j]=='#' ){
      sh = i;
   	  sw = j;
    }
}}
  
vm[sh][sw]=0;

  
for (int p=0;p<10000;p++){
  	if (sh+1<h){if (vm[sh+1][sw]==1){
      sh++;
      vm[sh][sw]=0;
    }}
  	if (sw+1<w){if (vm[sh][sw+1]==1){
      sw++;
       vm[sh][sw]=0;
    }}
}
  
for (int i=0;i<h;i++){
for (int j=0;j<w;j++){
	//cout<<vm[i][j];
}}  

int su=0;
for (int i=0;i<h;i++){
for (int j=0;j<w;j++){
	su+=vm[i][j];
}}  
if (su==0){
  cout << "Possible" << endl;
} else {
  cout << "Impossible" << endl;
}

return 0; 
  
}