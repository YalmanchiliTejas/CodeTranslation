#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >>H>>W;
  vector<vector<char>> masu(110,vector<char>(110));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>masu.at(i).at(j);
    }
  }
  //vector<int> judgegyou(110);
  int gyousuu=0;
  bool dot=true;
  
  for(int i=0;i<H;i++){
    dot=true;
    for(int j=0;j<W;j++){
      if(masu.at(i).at(j)!='.')dot=false;
    }
    if(dot){
      for(int j=i;j<H;j++){
       for(int k=0;k<W;k++){
  masu.at(j).at(k)=masu.at(j+1).at(k);
       }   
      }
      gyousuu++;//ドットの行数
      i--;
    }
  }

  int retsusuu=0;
  
  for(int j=0;j<W;j++){
    dot=true;
    for(int i=0;i<H-gyousuu;i++){
      if(masu.at(i).at(j)!='.')dot=false;
    }
    if(dot){
      for(int i=j;i<W;i++){
       for(int k=0;k<H-gyousuu;k++){
  masu.at(k).at(i)=masu.at(k).at(i+1);
       }   
      }
      retsusuu++;//ドットの行数
      j--;
    }
  }

  
  
  
  for(int i=0;i<H-gyousuu;i++){
   for(int j=0;j<W-retsusuu;j++){
    cout<<masu.at(i).at(j);
     if(j==W-retsusuu-1)cout<<endl;
   }
  }
}
