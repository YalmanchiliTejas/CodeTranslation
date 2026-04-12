#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;
 #define rep(i, n) for(int i = 0; i < (int)(n); i++)

 int main() {
   int n;
   cin >> n;
   vector<int> ans(26, 50);

   rep(i, n) {
     string s;
     vector<int> tmp(26, 0);
     cin >> s;
     rep(j, s.length()) tmp.at((int)(s.at(j) - 'a'))++;
     rep(k, 26) {
       ans.at(k) = min(ans.at(k), tmp.at(k));
     }
   }

   rep(i, 26) {
     if (ans.at(i) > 0) {
       rep(j, ans.at(i)) {
         cout << (char)(i + 'a');
       }
     }
   }
   cout << endl;
 }
