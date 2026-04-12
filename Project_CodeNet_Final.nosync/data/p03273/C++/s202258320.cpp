#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<bool> H(h,false),W(w,false);
  vector<string> s(h);
  for(int i=0;i<h;i++)
    cin >> s[i];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        H[i]=true;
        break;
      }
    }
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(s[j][i]=='#'){
        W[i]=true;
        break;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(H[i]){
      for(int j=0;j<w;j++){
        if(W[j])
          cout << s[i][j];
      }
      cout << endl;
    }
  }
}
       