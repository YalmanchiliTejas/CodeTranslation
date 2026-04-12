#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  bool sei;
  bool muzu=true;
  cin>>H>>W;
  vector<vector<char>>vec(H,vector<char>(W));
  vector<vector<bool>>ve(H,vector<bool>(W,true));
  for (int X=0;X<H;X++){
    sei=true;
    for (int Y=0;Y<W;Y++){
      cin>>vec.at(X).at(Y);
      if(vec.at(X).at(Y)=='#'){
        sei=false;
      }
    }
    if(sei==true){
      for (int L=0;L<W;L++){
        ve.at(X).at(L)=false;
      }
    }
  }  
  for (int Y=0;Y<W;Y++){
    sei=true;
    for (int X=0;X<H;X++){
      if(vec.at(X).at(Y)=='#'){
        sei=false;
      }
    }
    if(sei==true){
      for (int L=0;L<H;L++){
        ve.at(L).at(Y)=false;
      }
    }
  }
  for (int X=0;X<H;X++){
    muzu=true;
    for (int Y=0;Y<W;Y++){
      if (ve.at(X).at(Y)==true){
        cout<<vec.at(X).at(Y);
      }
    }
    for (int Y=0;Y<W;Y++){
      if (ve.at(X).at(Y)==true){
        muzu=false;
      }
    }
    if(muzu==false){
      cout<<endl;
    }
  }
}