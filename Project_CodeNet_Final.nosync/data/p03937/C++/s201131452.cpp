#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll H,W; cin>>H>>W;
  vector<string> path(H);
  rep(i,H)
  {
    cin>>path.at(i);
  }
  
  /*
  rep(i,H)
  {
    cout<<path.at(i)<<endl;
  }  
  */
  
  ll x=0,y=0;
  rep(i,1<<(H+W-2))
  {
    x=0,y=0;
    vector<string> vec=path;
    ll i2=i;
    rep(j,H+W-1)
    {
      if(j==0) {vec.at(0).at(0)='.'; continue;}
      if(i2&1)
      {
        x+=1;
        if(x>=W) {goto OUT;}
        if(vec.at(y).at(x)=='.') {goto OUT;}
        vec.at(y).at(x)='.';
      }
      else
      {
        y+=1;
        if(y>=H) {goto OUT;}
        if(vec.at(y).at(x)=='.') {goto OUT;}
        vec.at(y).at(x)='.';
      }
      i2>>=1;
    }
    rep(j,H)
    {
      rep(k,W)
      {
        if(vec.at(j).at(k)=='#') {goto OUT;}
      }
    }
    cout<<"Possible"<<endl; return 0;
OUT:
    i2+=1;
  }
  cout<<"Impossible"<<endl;
  return 0;
}
