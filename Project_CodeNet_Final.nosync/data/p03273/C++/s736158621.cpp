/**
*    author:  yuya1234
*    created: 08.07.2020 14:31:17
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define ALL(v) (s).begin(), (s).end()
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int h,w;
  cin>>h>>w;

  string s[h];
  REP(i,h)cin>>s[i];

  vector<string> v;
  bool flg;
  REP(i,h)
  {
    flg=true;
    REP(j,w)
    {
      if(s[i][j]=='#')flg=false;
    }
    if(!flg)v.emplace_back(s[i]);
  }

  vector<string> ans(SZ(v),"");
  REP(i,w)
  {
    flg=true;
    REP(j,SZ(v))
    {
      if(v[j][i]=='#')flg=false;
    }
    if(!flg)
    {
      REP(k,SZ(v))ans[k]+=v[k][i];
    }
  }

  REP(i,SZ(ans))cout<<ans[i]<<endl;

  return 0;
}