#include<iostream>
#include<string>
using namespace std;
int North(int *p){
  int mem;
  mem = p[1];
  p[1] = p[2];
  p[2] = p[6];
  p[6] = p[5];
  p[5] = mem;
  return p[1];
}
int East(int *p){
  int mem;
  mem = p[1];
  p[1] = p[4];
  p[4] = p[6];
  p[6] = p[3];
  p[3] = mem;
  return p[1];
}
int West(int *p){
  int mem;
  mem = p[1];
  p[1] = p[3];
  p[3] = p[6];
  p[6] = p[4];
  p[4] = mem;
  return p[1];
}
int South(int *p){
  int mem;
  mem = p[1];
  p[1] = p[5];
  p[5] = p[6];
  p[6] = p[2];
  p[2] = mem;
  return p[1];
}
int Right(int *p){
  int mem;
  mem = p[2];
  p[2] = p[3];
  p[3] = p[5];
  p[5] = p[4];
  p[4] = mem;
  return p[1];
}
int Left(int *p){
  int mem;
  mem = p[2];
  p[2] = p[4];
  p[4] = p[5];
  p[5] = p[3];
  p[3] = mem;
  return p[1];
}
int main(){
  int n,p[7];;
  string com;
  while(cin >> n){
    if(n==0) break;
    int s = 1;
    for(int i=0;i<=6;i++) p[i] = i;
    for(int i=0;i<n;i++){
      cin >> com;
      if(com=="North") s += North(p);
      else if(com=="East") s += East(p);
      else if(com=="West") s += West(p);
      else if(com=="South") s += South(p);
      else if(com=="Right") s += Right(p);
      else s += Left(p);
    }
    cout << s << endl;
  }
  return 0;
}