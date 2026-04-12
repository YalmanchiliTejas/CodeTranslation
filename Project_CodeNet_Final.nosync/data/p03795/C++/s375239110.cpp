#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;

  int x, y;
  x = 800 * N;
  y = 200 * (N / 15);
  cout << x - y << endl;
}
