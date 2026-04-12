#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

int calc1(string n) {
  int nn = (int)n.size();
  int ans = 0;
  for (int digit=1; digit<=nn-1; digit++) {
    ans += 9;
  }
  ans += (int)(n[0] - '0');
  return ans;
}

int calc2(string n) {
  int nn = (int)n.size();
  int ans = 0;  
  for (int digit=1; digit<=nn-1; digit++) {
    ans += 81 * (digit - 1);
  }
  ans += (int)((n[0] - '0') - 1) * (nn-1) * 9;
  n[0] = '0';
  while (n.size() > 1) {
    if (n[0] == '0') {
      n.erase(n.begin());
    } else {
      break;
    }
  }
  ans += calc1(n);
  return ans;
}

int calc3(string n) {
  int nn = (int)n.size();
  int ans = 0;  
  for (int digit=1; digit<=nn-1; digit++) {
    ans += 729 * ((digit - 1) * (digit - 2) / 2);
  }
  ans += (int)((n[0] - '0') - 1) * (nn-1) * (nn-2) * 9 * 9 / 2;
  n[0] = '0';  
  while (n.size() > 1) {
    if (n[0] == '0') {
      n.erase(n.begin());
    } else {
      break;
    }
  }
  ans += calc2(n);
  return ans;
}

int main() {
  string n;
  int k;
  cin >> n;
  cin >> k;
  int ans = 0;
  int nn = (int)n.size();
  if (k == 1) {
    ans = calc1(n);
  } else if (k == 2) {
    ans = calc2(n);
  } else {
    ans = calc3(n);    
  }
    
  cout << ans << endl;
  
  return 0;
}
