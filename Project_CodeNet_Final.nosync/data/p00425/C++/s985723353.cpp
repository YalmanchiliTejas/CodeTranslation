#include<iostream>
#include<string>
using namespace std;
int p[7];
int North(){
  int mem;
  mem = p[1];
  p[1] = p[2];
  p[2] = p[6];
  p[6] = p[5];
  p[5] = mem;
  return p[1];
}
int East(){
  int mem;
  mem = p[1];
  p[1] = p[4];
  p[4] = p[6];
  p[6] = p[3];
  p[3] = mem;
  return p[1];
}
int West(){
  int mem;
  mem = p[1];
  p[1] = p[3];
  p[3] = p[6];
  p[6] = p[4];
  p[4] = mem;
  return p[1];
}
int South(){
  int mem;
  mem = p[1];
  p[1] = p[5];
  p[5] = p[6];
  p[6] = p[2];
  p[2] = mem;
  return p[1];
}
int Right(){
  int mem;
  mem = p[2];
  p[2] = p[3];
  p[3] = p[5];
  p[5] = p[4];
  p[4] = mem;
  return p[1];
}
int Left(){
  int mem;
  mem = p[2];
  p[2] = p[4];
  p[4] = p[5];
  p[5] = p[3];
  p[3] = mem;
  return p[1];
}
int main(){
  int n;
  string com;
  while(cin >> n){
    if(n==0) break;
    int s = 1;
    for(int i=0;i<=6;i++) p[i] = i;
    for(int i=0;i<n;i++){
      cin >> com;
      if(com=="North") s += North();
      else if(com=="East") s += East();
      else if(com=="West") s += West();
      else if(com=="South") s += South();
      else if(com=="Right") s += Right();
      else s += Left();
    }
    cout << s << endl;
  }
  return 0;
}