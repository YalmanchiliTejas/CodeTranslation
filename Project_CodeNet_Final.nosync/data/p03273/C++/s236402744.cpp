#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w; cin>>h>>w;
  vector<string> a(h);
  for (int i=0; i<h; i++) cin>>a[i];
  
  vector<bool> row(h,false);
  vector<bool> col(h,false);
  
  for (int i; i<h; i++){
    for (int j=0; j<w; j++){
      if (a[i][j]=='#'){
        row[i]=true;
        col[j]=true;
      }
    }
  }
  
  for (int i; i<h; i++){
    int check=0;
    for (int j=0; j<w; j++){
      if (row[i]==true && col[j]==true){
        check=1;
        cout<<a[i][j];
      }
    }
    if (check==1) cout<<endl;
  }
}