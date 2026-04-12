#include<iostream>
#include<vector>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> c(H,vector<char>(W));
  vector<bool> b1(H),b2(W);
  vector<vector<bool>> b(H,vector<bool>(W));
  
  for(int i=0;i<H;i++){
    b1.at(i)=false;
    for(int j=0;j<W;j++){
      cin>>c.at(i).at(j);
      b2.at(j)=false;
    }
  }
  
  for(int i=0;i<H;i++){
    int mark=0;
    for(int j=0;j<W;j++){
      if(c.at(i).at(j)=='#'){mark=1;break;}
    }
    if(mark==0){b1.at(i)=true;}
  }
  
  for(int i=0;i<W;i++){
    int mark=0;
    for(int j=0;j<H;j++){
      if(c.at(j).at(i)=='#'){mark=1;break;}
    }
    if(mark==0){b2.at(i)=true;}
  }
  
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(b1.at(i)){continue;}
      if(b2.at(j)){continue;}
      cout<<c.at(i).at(j);
    }
    if(b1.at(i)){continue;}
    cout<<endl;
  }
}

