#include<iostream>
#include<iomanip>
using namespace std;
void x_y(int x,int y,int n){
  if(x>=n) x = 0;
  if(y>=n) y = 0;
  if(x<0) x = n - 1;
  //if(y<0) y = n - 1;
}  
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;
    int magic[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) magic[j][i] = 0;
    }
    magic[n/2][n/2+1] = 1;
    int x = n / 2;
    int y = n / 2 + 1;
    int count = 1;
    //cout << x << ' ' << y << endl;
    while(count!=n*n){
      count++;
      //x_y(x+1,y+1,n);
      if(x+1>=n) x = 0;
      else x++;
      if(y+1>=n) y = 0;
      else y++;
      //cout << x << ' ' << y << endl;
      while(magic[x][y]!=0){
	//x_y(x-1,y+1,n);
	if(x-1<0) x = n - 1;
	else x--;
	if(y+1>=n) y = 0;
	else y++;
      } 
      magic[x][y] = count;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cout << setw(4) << magic[j][i];
      }
      cout << endl;
    }
  }
  return 0;
} 