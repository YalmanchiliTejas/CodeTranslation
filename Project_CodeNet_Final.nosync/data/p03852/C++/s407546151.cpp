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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string vowel = "aiueo";
int main() {
  char a;
  cin >> a;
  for(int i = 0; i < vowel.size(); i++) {
    if(a == vowel[i]) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  
    return 0;
}
