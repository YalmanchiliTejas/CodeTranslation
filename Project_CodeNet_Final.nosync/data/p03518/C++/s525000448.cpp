#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector<int> p(n);
   for (int i = 0; i < n; ++i) {
      cin >> p[i];
   }
   auto finish = [&]() {
      for (int i = 0; i < n; ++i) {
         if (p[i] != i) return false;
      }
      return true;
   };
   vector<int> ans;
   auto go = [&](int k) {
      ans.push_back(k);
      for (int i = k; i < n; ++i) {
         swap(p[i], p[i - k]);
      }
   };
   while (!finish()) {
      if (p[0] < p[n - 1] && p[n - 1] != (n - 1)) {
         go(n - 1);
      } else {
         go(1);
      }
   }
   cout << ans.size() << "\n";
   for (int v : ans) {
      cout << v << "\n";
   }
}
