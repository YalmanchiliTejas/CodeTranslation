#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int h;
  cin >> h;
  int w;
  cin >> w;
  vector<string> a(h);
  for(int i=0; i<h; i++)
    cin >> a[i];
 
  vector<bool> col(h, false);
  vector<bool> row(w, false);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if( a[i][j] =='#'){
        col[i] =true;
        row[j] =true;
      } 
    }
  }
  
  for(int i=0; i<h; i++){
    if(col[i]){
      for(int j=0; j<w; j++){
        if(row[j])
          cout << a[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}  