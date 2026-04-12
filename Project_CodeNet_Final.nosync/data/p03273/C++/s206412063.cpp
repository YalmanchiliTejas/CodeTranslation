#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int h,w;
  cin >> h >> w;
  char a[h][w]={};
  bool hei[h]={},wid[w]={};
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> a[i][j];
      if(a[i][j]=='#') {
        hei[i]=true,wid[j]=true;
      }
    }
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(hei[i]==true&&wid[j]==true) {
        cout << a[i][j];
      }
    }
    if(hei[i]==true) {
      cout << endl;
    }
  }
}