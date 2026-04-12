#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;
static const ll LOGN=55;




int main(void) {
  string s;
  cin >> s;
  
  ll cnt[2]={};
  for(ll i=0; i<s.size(); i++) {
    cnt[s[i]-'A']++;
  }
  
  if(cnt[0]==3||cnt[1]==3) {
    pt("No");
  }else {
    pt("Yes");
  }
  
  
  
  
  
}




