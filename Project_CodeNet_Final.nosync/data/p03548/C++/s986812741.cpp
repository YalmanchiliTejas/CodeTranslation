#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
using namespace std;
int input(){
  int x;
  cin>>x;
  return x;
}
int abs(int x){
  if(x>=0){
    return x;
  }else{
    return -x;
  }
}
int gcd(int x, int y){
	if(x<y){
    return gcd(y,x);
  }
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}
int moji(char i){
  if(i=='a'){
    return 1;
  }
  if(i=='b'){
    return 2;
  }
  if(i=='c'){
    return 3;
  }
  if(i=='d'){
    return 4;
  }
  if(i=='e'){
    return 5;
  }
  if(i=='f'){
    return 6;
  }
  if(i=='g'){
    return 7;
  }
  if(i=='h'){
    return 8;
  }
  if(i=='i'){
    return 9;
  }
  if(i=='j'){
    return 10;
  }
  if(i=='k'){
    return 11;
  }
  if(i=='l'){
    return 12;
  }
  if(i=='m'){
    return 13;
  }
  if(i=='n'){
    return 14;
  }
  if(i=='o'){
    return 15;
  }
  if(i=='p'){
    return 16;
  }
  if(i=='q'){
    return 17;
  }
  if(i=='r'){
    return 18;
  }
  if(i=='s'){
    return 19;
  }
  if(i=='t'){
    return 20;
  }
  if(i=='u'){
    return 21;
  }
  if(i=='v'){
    return 22;
  }
  if(i=='w'){
    return 23;
  }
  if(i=='x'){
    return 24;
  }
  if(i=='y'){
    return 25;
  }
  if(i=='z'){
    return 26;
  }
  return 100;
  
}




int main() {
  int X=input();
  int Y=input();
  int Z=input();
  X-=Y+Z+Z;
  int sum=1;
  while(X>=Y+Z){
    X-=Y+Z;
    sum++;

  }
  cout<<sum<<endl;
  
  


  


  

  




  
  
}
