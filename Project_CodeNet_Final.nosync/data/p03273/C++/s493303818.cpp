#include<iostream>
#include<vector>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;

  vector<string>s(H);
  for(int i=0;i<H;i++){
    cin >> s.at(i);
  }
  vector<bool>row(H,false);
  vector<bool>col(W,false);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s.at(i).at(j)=='#'){
        row.at(i)=true;
        col.at(j)=true;
      }
    }
  }

  for(int i=0;i<H;i++){
    if(row.at(i)){
      for(int j=0;j<W;j++){
        if(col.at(j)){
          cout << s.at(i).at(j);
        }
      }
      cout <<endl;
    }
  }
}
