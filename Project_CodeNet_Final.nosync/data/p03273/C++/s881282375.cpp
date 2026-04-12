#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i=0; i< h;i++) cin >> a[i];

  vector<bool> column(h,false);
  vector<bool> row(w,false);

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        column[i]=true;
        row[j]=true;
      }
    }
  }
  for (int i=0;i<h;i++){
    if(column[i]){
      for (int j=0;j<w;j++){
        if(row[j]) cout << a[i][j];
      }
    }
    cout << endl;
  }
}