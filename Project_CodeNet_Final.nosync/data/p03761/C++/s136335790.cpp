//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=5e18;
using P=pair<int,int>;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  int cnt[30]={};
  cin >> n;
  for(int i=0; i<30; i++) {
    cnt[i]=inf;
  }
  for(int i=0; i<n; i++) {
    cin >> s;
    int x[30]={};
    for(auto p:s) {
      x[p-'a']++;
    }
    for(int i=0; i<30; i++) {
      cnt[i]=min(cnt[i],x[i]);
    }
  }
  for(int i=0; i<26; i++) {
    for(int j=0; j<cnt[i]; j++) {
      cout << char('a'+i);
    }
  }
  cout << endl;
}