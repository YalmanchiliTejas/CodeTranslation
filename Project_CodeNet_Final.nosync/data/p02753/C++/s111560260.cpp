#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   string s;
   cin >> s;

   sort(s.begin(), s.end());

   if (s[0] != s[1] || s[1] != s[2]) {
       cout << "Yes" << endl;
   } else {
       cout << "No" << endl;
   }
}