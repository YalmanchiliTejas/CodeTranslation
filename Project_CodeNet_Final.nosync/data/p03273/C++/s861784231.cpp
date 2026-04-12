#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
 
int main()
{
  int H, W, last, count=0;
  char c;
  cin >> H >> W;
  last=H*W;
  vector<char> all(11111,'.'), warp(H,0), weft(W,0);

  rep(i,H)
  {
    rep(j,W)
    {
      cin >> c;
      if(c=='#')
      {
        all.at(i*H+j)='#';
        warp.at(i)=1;
        weft.at(j)=1;
      }
    }
  }
  rep(i,H)
  {
    if(warp.at(i)==0)
      continue;
    rep(j,W)
    {
      if(weft.at(j)==0)
        continue;
      else
        cout<<all.at(i*H+j);
    }
    cout<<endl;
  }
}