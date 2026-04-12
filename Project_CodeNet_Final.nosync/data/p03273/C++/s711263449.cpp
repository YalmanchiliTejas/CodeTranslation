#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll H,W; cin>>H>>W;
  vector<string> Grid(H);
  rep(i,H)
  {
    cin>>Grid.at(i);
  }
  
  
  vector<ll> tatejiku(0);
  string hoge="";
  rep(i,W)
  {
    hoge+=".";
  }
  rep(i,H)
  {
    if(Grid.at(i)!=hoge) {tatejiku.push_back(i);}
  }
  
  
  
  vector<ll> yokojiku(0);
  rep(i,W)
  {
    rep(j,H)
    {
      if(Grid.at(j).at(i)=='#') {yokojiku.push_back(i); break;}
    }
  }
  
  
  for(auto p:tatejiku)
  {
    for(auto q:yokojiku)
    {
      cout<<Grid.at(p).at(q);
    }
    cout<<endl;
  }
  return 0;
}
