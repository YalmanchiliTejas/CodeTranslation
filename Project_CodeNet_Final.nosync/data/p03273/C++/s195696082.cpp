#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
  int h,w;
  string* a = new string[100];
  cin >> h >> w;
  bool* hb = new bool[100];
  bool* wb = new bool[100];
  for(int i=0;i<h;i++) cin >> a[i];
  for(int i=0;i<h;i++) hb[i] = false;
  for(int i=0;i<w;i++) wb[i] = false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        hb[i] = true;
        wb[j] = true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(!hb[i]) continue;
    for(int j=0;j<w;j++){
      if(hb[i] && wb[j]){
        cout << a[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
