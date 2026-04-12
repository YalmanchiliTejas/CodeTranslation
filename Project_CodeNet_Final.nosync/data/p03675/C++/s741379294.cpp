#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)a.size()
#define int int64_t
const int MAXN = 2e5 + 1;
template<typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p) {
     out << "{" << p.first << ", " << p.second << "} ";//optional
     return out;
}

template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
     in >> p.first >> p.second;
     return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
     for (auto &i : arr)
          in >> i;
     return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
     for (int i = 0; i < (int)arr.size(); ++i) {
          if (i != 0) {
               out << ' ';
          }
          out << arr[i];//optional
     }
     out << endl;
     return out;
}


signed main() {
     int n;
     cin >> n;
     vector<int> a(n);
     cin >> a;
     vector<int> ans(n);
     int l = 0;
     if (n % 2 == 1) {
          vector<int> aa = a;
          aa.pop_back();
          for (int i = n - 2; i >= 0; i -= 2) {
               ans[l++] = aa[i];
          }
          for (int i = 0; i < n - 1; i += 2) {
               ans[l++] = aa[i];
          }
          ans.back() = a.back();
          reverse(ans.begin(), ans.end());
     }
     l = 0;
     if (n % 2 == 0) {
          for (int i = n - 1; i >= 0; i -= 2) {
               ans[l++] = a[i];
          }
          for (int i = 0; i < n; i += 2) {
               ans[l++] = a[i];
          }
     }
     cout << ans << endl;
     return 0;
}