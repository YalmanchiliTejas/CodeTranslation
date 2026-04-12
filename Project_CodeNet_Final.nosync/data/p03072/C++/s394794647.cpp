#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N; cin >> N;

  vector<int> H(N);
  rep( i, 0, N ) cin >> H.at(i);

  int Ans = 1;
  int temp = H.front();
  rep( i, 1, N ) {
    if ( temp <= H.at(i) ) {
      Ans++;
      temp = H.at(i);
    }
  }

  cout << Ans << endl;
}
