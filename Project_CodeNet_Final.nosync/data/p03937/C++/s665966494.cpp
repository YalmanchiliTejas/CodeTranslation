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
  ll h,w;cin>>h>>w;
  vector<vector<char> >a(h,vector<char>(w));
  rep(i,h){
    rep(j,w)cin>>a[i][j];
  }
  ll count=0;
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#')count++;
    }
  }
  if(count==h+w-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}