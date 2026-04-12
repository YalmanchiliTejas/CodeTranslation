#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

// index が条件を満たすかどうか
bool isOK(vector<int> & a, int index, int key) {
    if (a[index] < key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(vector<int> & a, int key) {
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(a, mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
  int n;
  cin >> n;
  vector<int> la(n);
  for (int i = 0; i < n; ++i) {
    cin >> la[i];
  }
  vector<int> lc;
  lc.push_back(la[0]);
  for (int i = 1; i < la.size(); ++i) {
    int key = la[i];
    int ret = binary_search(lc, key);
    if (ret == lc.size()) {
      lc.push_back(key);
    }
    else {
      lc[ret] = key;
    }
  }
  cout << lc.size() << endl;
}
