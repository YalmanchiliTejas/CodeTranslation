#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int W, H;
  cin >> H >> W;
  
//  vector<string> data(H); 
  vector<vector<char>> data(H, vector<char>(W));
  
  vector<bool> flagW(W,false);
  vector<bool> flagH(H,false);
  
  for(int j=0; j<H; j++)
  {
    string a;
    cin >> a;
      
    for(int i=0; i<W; i++)
    {
      data[j][i] = a[i];
 	}
  }
   
  // check w
  for(int j=0; j<H; j++)
  {
    for(int i=0; i<W; i++)
    {
      if(data[j][i]=='#') flagH[j] = true;
 	}
  }
  
  // check h
  for(int i=0; i<W; i++)
  {
    for(int j=0; j<H; j++)
    {
      if(data[j][i]=='#') flagW[i] = true;
 	}
  }
  
  for(int j=0; j<H; j++)
  {
    if(!flagH[j]) continue;
    
    for(int i=0; i<W; i++)
    {
      if(!flagW[i]) continue;
      cout << data[j][i];
 	}
    cout << endl;
  }
}