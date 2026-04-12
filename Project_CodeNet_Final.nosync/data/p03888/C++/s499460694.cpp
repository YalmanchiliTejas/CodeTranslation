#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
  double a, b, c;
  cin >> a >> b;
  c = (1 / a) + (1 / b);
  c = 1 / c;
  cout << fixed << setprecision(20) << c << endl;
    return 0;
}
