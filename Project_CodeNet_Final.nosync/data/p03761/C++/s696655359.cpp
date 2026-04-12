#include <bits/stdc++.h>
using namespace std;

int a[30];
int b[30];

int main() {
   fill(a, a+26, 1e5);

   int n;
   cin >> n;
   while (n--) {
      string s;
      cin >> s;
      fill(b, b+26, 0);
      for (char c : s) {
         b[c-'a']++;
      }
      for (int i = 0; i < 26; i++) {
         a[i] = min(a[i], b[i]);
      }
   }

   string ans = "";
   for (int i = 0; i < 26; i++) {
      ans += string(a[i], 'a'+i);
   }
   cout << ans << endl;

   return 0;
}