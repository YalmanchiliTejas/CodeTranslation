#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)


int main() {
  int n;
  cin >> n;
  vector<int> n1, n2;
  rep(i, n){
      int num; cin >> num;
      if(i % 2 == 0) n1.push_back(num);
      else n2.push_back(num);
  }
  if(n % 2 == 0){
      reverse(all(n2));
      rep(i, n2.size()) cout << n2[i] << " ";
      rep(i, n1.size()){
          cout << n1[i];
          cout << " ";
          }
  } else{
      reverse(all(n1));
      rep(i, n1.size()) cout << n1[i] << " ";
      rep(i, n2.size()){
        cout << n2[i];
        cout << " ";
      }
  } cout << ln;
}