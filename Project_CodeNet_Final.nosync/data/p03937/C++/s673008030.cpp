#include<bits/stdc++.h>
#define rep(i,n)  for(ll i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int h,w; cin >> h >> w;
  char a;
  int cnt = 0;
  rep(i,h) rep(j,w){ cin >> a; if(a=='#') cnt++; }
  cout << (cnt == h+w-1 ? "Possible" : "Impossible");
  cout << "\n";
  return 0;
}
