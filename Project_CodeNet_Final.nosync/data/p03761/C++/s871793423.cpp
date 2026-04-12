#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  vl cnt(26,INF);
  ll n;
  cin >> n;
  rep(i,n){
    string s;
    cin >> s;
    rep(i,26){
      ll x=0;
      rep(j,s.size()){
        if(abc[i]==s[j]){
          x++;
        }
      }
      cnt[i]=min(cnt[i],x);
    }
  }
  string t="";
  rep(i,26){
    rep(j,cnt[i]){
      t+=abc[i];
    }
  }
  cout << t << endl;
}