#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

ll to_int(char& c)
{
  return (c-'0');
}
string rep9(int n)
{
  string ret="";
  for (int i = 0; i < n; ++i)
  {
    ret.push_back('9');
  }
  return ret;
}

string del0(string s)
{
  while(s[0]=='0')
  {
    s=s.substr(1);
  }
  return s;
}

ll solve1(string n)
{
  if(n=="") return 0;
  ll ans=(n.size()-1)*9;
  ans+=to_int(n[0]);
  return ans;
}

ll solve2(string n)
{
  if(n=="") return 0;
  // start with 0
  ll ans=(n.size()-1)*(n.size()-2)/2*81;
  // start with 1 ~ (n[0]-1)
  ans+=(to_int(n[0])-1)*solve1(rep9(n.size()-1));
  // start with n[0]
  ans+=solve1(del0(n.substr(1)));
  return ans;
}

ll solve3(string n)
{
  // start with 0
  ll ans=(n.size()-1)*(n.size()-2)*(n.size()-3)/6*729;
  // start with 1 ~ (n[0]-1)
  ans+=(to_int(n[0])-1)*solve2(rep9(n.size()-1));
  // start with n[0]
  ans+=solve2(del0(n.substr(1)));
  return ans;
}

int main()
{
  string n;
  int k;
  cin>>n>>k;
  if(n.size()<k)
  {
    cout<<0;
    return 0;
  }
  if(k==1) cout<<solve1(n);
  else if(k==2) cout<<solve2(n);
  else cout<<solve3(n);
}