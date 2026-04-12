#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
typedef long long ll;

int n,k;
string s[100000];

int main() {
  cin >> n ;
  rep(i,n) cin >> s[i];
  map<char,int> mp;
  for(char c='a';c<='z';c++) mp[c]=1e9;
  rep(i,n)for(char c='a';c<='z';c++){
    int cnt=count(all(s[i]),c);
    mp[c]=min(mp[c],cnt);
  }
  string ans;
  for(char c='a';c<='z';c++){
    rep(i,mp[c]) ans+=c;
  }
  cout << ans << endl;
}