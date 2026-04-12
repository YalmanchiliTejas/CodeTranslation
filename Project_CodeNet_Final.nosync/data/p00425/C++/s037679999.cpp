#include<iostream>
#include<string>
using namespace std;
int main(){
  string dir;
  while(1){
  int dice[3] = {1,2,3},d,n;
  cin>>n;
  int s=1;
  if(!n)break;
  for(;n>0;n--){
    cin>>dir;
    int a,b;
    if(dir=="North")a=1,b=0;
    if(dir=="East")a=0,b=2;
    if(dir=="West")a=2,b=0;
    if(dir=="South")a=0,b=1;
    if(dir=="Right")a=2,b=1;
    if(dir=="Left")a=1,b=2;
    d = dice[a];
    dice[a] = 7-dice[b];
    dice[b] = d;
    s+=dice[0];
  }
  cout<<s<<endl;
  }
  return 0;
}