//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  vector<ll>count(26,INF);
  rep(i,n){
    string s;cin>>s;
    vector<ll>part(26,0);
    for(int j=0;j<26;j++){
      for(int k=0;k<s.size();k++){
        if(abc[j]==s[k])part[j]++;
      }
    }
    for(int j=0;j<26;j++){
      count[j]=min(count[j],part[j]);
    }
  }
  rep(i,26){
    if(count[i]==INF)continue;
    rep(j,count[i])cout<<abc[i];
  }
  cout<<endl;
}
  