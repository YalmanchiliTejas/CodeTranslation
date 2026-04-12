#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  bool col[w]={}, row[h]={};
  string a[h];
  for(int i=0;i<h;i++)
    cin >> a[i];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(!row[i]) continue;
    for(int j=0;j<w;j++){
      if(col[j]){
        cout << a[i][j];
      }
    }
    cout << endl;
  }
  
}