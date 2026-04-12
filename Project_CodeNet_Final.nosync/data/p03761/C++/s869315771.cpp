/**
*    author:  yuya1234
*    created: 14.07.2020 15:32:32
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long double eps = 1.0E-14;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a,T b){return gcd(a,b)*(a/gcd(a,b))*(b/gcd(a,b));}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  int n;
  cin>>n;

  string s[n];
  REP(i,n)cin>>s[i];

  int a[26][n];
  REP(i,26)REP(j,n)
  {
    a[i][j]=0;
  }

  REP(i,n)
  {
    REP(j,SZ(s[i]))
    {
      a[s[i][j]-'a'][i]++;
    }
  }

  string ans="";
  int cnt;
  REP(i,26)
  {
    cnt=INT_MAX;
    REP(j,n)
    {
      cnt=min(cnt,a[i][j]);
    }
    REP(k,cnt)
    {
      ans+=char(i+'a');
    }
  }
  
  cout<<ans<<endl;

  return 0;
}