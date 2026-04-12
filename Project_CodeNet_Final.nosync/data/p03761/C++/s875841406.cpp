#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  int n;
  cin >> n;
  map<char,int> now;
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  rep(i,27) now[alpha[i]] = 51;
  rep(i,n){
    string a;
    map<char,int> b;
    rep(i,27) b[alpha[i]] = 0;
    cin >> a;
    rep(j,a.size()) b[a[j]] ++;
    for(auto j:b){
      now[j.first] = min(j.second,now[j.first]);
    }
  }
  char ans;
  for(auto i:now){
    if(i.second==51) continue;
    rep(j,i.second) cout << i.first;
  }
  cout << endl;
      
  
  return 0;
}


