#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int n,count=0,highest=0;
  cin >> n;
  vi h(n);
  rep(i,n) cin >> h[i];
  rep(i,n){
    if(highest <= h[i]){
      count++;
      highest = h[i];
    }
  }
  cout << count << endl;
}
