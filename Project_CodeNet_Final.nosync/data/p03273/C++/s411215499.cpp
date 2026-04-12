#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define REPRl(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < (int)n; i++)
#define FORl(i, m, n) for(ll i = m; i < (ll)n; i++)
#define ALL(v) v.begin(), v.end()
ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
int main() {
  int h,w;cin>>h>>w;
  vector<string> g(h);
  REP(i,h){
    string s;cin>>s;
    g[i]=s;
  }
  vector<bool> hh(h);
  vector<bool> ww(w);
  string white=string(w,'.');
  REP(i,h){
    hh[i]=(g[i]==white);
  }
  REP(j,w){
    bool lines=true;
    REP(i,h){
      if(g[i][j]!='.'){
        lines=false;
      }
    }
    ww[j]=lines;
  }
  REP(i,h){
    if(hh[i])continue;
    REP(j,w){
      if(ww[j])continue;
      cout << g[i][j];
    }
    cout<<endl;
  }
}