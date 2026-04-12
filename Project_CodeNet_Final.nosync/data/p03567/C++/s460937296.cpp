#include <bits/stdc++.h>

 using namespace std;
 int main() {
   string S, ans;
   int i;

   cin >> S;
   ans = "No";

   for (i = 0; i < S.length() - 1; i++) {
     if (S.at(i) == 'A' && S.at(i + 1) == 'C') {
       ans = "Yes";
       break;
     }
   }
   cout << ans << endl;
 }
