#include<iostream>
#include<string>
using namespace std;
int main(){
  int w,h;
  string a[8];
  int an[8][8]={};
  cin >> h >> w;
  for(int i=0;i<h;i++){
    cin >> a[i];
  }
  an[0][0]=1;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
	if(i!=0){
	  if(an[i-1][j]==1){
	    an[i-1][j]=0;
	    an[i][j]=1;
	  }
	}
	if(j!=0){
	  if(an[i][j-1]==1){
	    an[i][j-1]=0;
	    an[i][j]=1;
	  }
	}
	if(an[i][j]!=1){
	  i=h;
	  break;
	}
	
      }
    }
  }
  if(an[h-1][w-1]==1)cout << "Possible"<< endl;
  else cout << "Impossible"<< endl;
  return 0;
}