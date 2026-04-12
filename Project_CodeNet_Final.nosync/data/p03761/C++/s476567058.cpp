#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
  int n;
  string ans="";
  cin >> n;
  vector<string> s(n);
  vector<int> c(n,0);
  char abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  rep(i, n){
    cin >> s.at(i);
    sort(all(s.at(i)));
  }
  rep(i, 26){
    rep(j, n){
      rep(k, s.at(j).size())if(s.at(j)[k] == abc[i])c.at(j)++;
    }
    rep(j, *min_element(all(c)))ans+=abc[i];
    rep(j, n) c.at(j)=0;
  }
  cout << ans;
}