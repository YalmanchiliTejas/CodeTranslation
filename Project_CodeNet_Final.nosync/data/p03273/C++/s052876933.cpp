#include<bits/stdc++.h>
using namespace std;
 
int main() {
  //input
  int h, w;
  cin >> h >>w;
  char a[h][w];
  for(int i(0);i<h;i++)
    for(int j(0);j<w;j++)
      cin >> a[i][j];
  //make_output
  int ch(h), cw(w);
  char b[h][w], c[h][w];
  
  //horizontal
  int count(0);
  for(int i(0);i<h;i++){
    bool p(true);
    for(int j(0);j<w;j++){
      if(a[i][j]=='#'){
        p=false;
        break;
      }
    }
    if(p)
      ch--;
    else{
      for(int j(0);j<w;j++)
        b[count][j] = a[i][j];
      count++;
    }	
  }
  
  //virtical
  count = 0;
  for(int j(0);j<w;j++){
    bool p(true);
    for(int i(0);i<ch;i++){
      if(b[i][j]=='#'){
        p=false;
        break;
      }
    }
    if(p)
      cw--;
    else{
      for(int i(0);i<ch;i++)
        c[i][count] = b[i][j];
      count++;
    }	
  }
  
  //output
  for(int i(0);i<ch;i++){
    for(int j(0);j<cw;j++)
      cout << c[i][j];
    cout << endl;
  }
}