#include<bits/stdc++.h>
using namespace std;

int main()
{
  int H,W;
  cin >>H>>W;
  vector<vector<char>> s(H,vector<char>(W));
  
  //data input
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin>>s.at(i).at(j);
    }
  }
  
  vector<bool> dw(W,false);
  vector<bool> dh(H,false);
  
  for(int i=0; i<H; i++){
    int cw=0;
    for(int j=0; j<W; j++){
      if(s.at(i).at(j)=='.') cw++;
    }
    if (cw==W) dh.at(i)=true;
  }
  
  for(int j=0; j<W; j++){
    int ch=0;
    for(int i=0; i<H; i++){
      if(s.at(i).at(j)=='.') ch++;
    }
    if(ch==H) dw.at(j)=true;
  }
  
  for(int i=0; i<H; i++){
    if(dh.at(i)==true) continue;
    for(int j=0; j<W; j++){
      if(dw.at(j)==true) continue;
      cout<<s.at(i).at(j);
    }
    cout<<endl;
  }
}