#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector <char> > masu(H,vector <char>(W));
  int h=0,i,j;
  vector<char> w(W);
  bool check;
  for(i=0;i<H;i++){
    check=false;
    for(j=0;j<W;j++){
      cin >> w.at(j);
      if(w.at(j)=='#'){
        check=true;
      }
    }
    if(check){
      masu.at(h)=w;
      h++;
    }
  }
  /*
  for(i=0;i<h;i++){
    for(j=0;j<W;j++){
      cout << masu.at(i).at(j);
    }
    cout << endl;
  }
  */
  
  vector<int> check_retu;
  for(i=0;i<W;i++){
    check=false;
    for(j=0;j<h;j++){
      //cout << masu.at(j).at(i);//
      if(masu.at(j).at(i)=='#'){
        check=true;
      }
    }
    if(check){
      //cout << "check_retu_push" << i << endl;//
      check_retu.push_back(i);
    }
  }
  for(i=0;i<h;i++){
    for(j:check_retu){
      cout << masu.at(i).at(j);
    }
    cout << endl;
  }
}