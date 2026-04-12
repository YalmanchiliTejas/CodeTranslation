#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll n; cin>>n;
  vector<string> S(n);
  rep(i,n)
  {
    cin>>S.at(i);
  }
  vector<ll> moji(26,1000);
  rep(i,n)
  {
    string s=S.at(i);
    vector<ll> moji2(26);
    rep(j,S.at(i).size())
    {
      moji2.at(s.at(j)-'a')++;
    }
    rep(j,26)
    {
      moji.at(j)=min(moji.at(j),moji2.at(j));
    }
  }
  rep(i,26)
  {
    char ch='a'+i;
    rep(j,moji.at(i))
    {
      cout<<ch;
    }
  }
  cout<<""<<endl;
  return 0;
}
