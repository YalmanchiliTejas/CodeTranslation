#include <iostream>
#define T 13
using namespace std;
int Change(char);

int main(){
  int cnt,c;
  char trump,b;
  string d[4][T]; //nesw
  while(1){
    cin>>trump;
    if(trump=='#') break;
    for(int i=0;i<4;i++)
      for(int j=0;j<T;j++) cin>>d[i][j];
    c=cnt=0;
    for(int i=0;i<T;i++){
      b=d[c][i][1];
      int f=0,ma=0,winner;
      for(int j=0;j<4;j++)
	if(d[j][i][1]==trump){
	  f=1;
	  int v=Change(d[j][i][0]);
	  if(ma<v) ma=v,winner=j;
	}
      if(f){
	if(winner%2) cnt++;
	c=winner;
	continue;
      }
      for(int j=0;j<4;j++){
	if(d[j][i][1]==b){
	  int v=Change(d[j][i][0]);
	  if(ma<v) ma=v,winner=j;
	}
      }
      if(winner%2) cnt++;
      c=winner;
    }
    if(cnt>=7) cout<<"EW "<<cnt-6<<endl;
    else cout<<"NS "<<7-cnt<<endl;
  }
  return 0;
}

int Change(char x){
  int v;
  if('0'<=x&&x<='9') v=x-'0';
  else if(x=='A') v=20;
  else if(x=='K') v=15;
  else if(x=='Q') v=12;
  else if(x=='J') v=11;
  else if(x=='T') v=10;
  return v;
}