#include<iostream>
#include<vector>

using namespace std;

int main(){
  int N; cin >> N; int hight = 0; int cnt = 0;
  for(int i = 0; i < N; i++){
    int H; cin >> H;
    if(hight <= H){cnt++;}
    hight = max(hight,H);}
  
  cout << cnt << endl;
  
  return 0;}