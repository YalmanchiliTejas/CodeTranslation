#include <bits/stdc++.h>
using namespace std;

int main() {
 string s;
 cin >> s;
 string ret = "No";

 int n = s.length();
 char first = s[0];
 for (int i = 1; i < n; i++) {
     if(s[i] != first) {
         ret = "Yes";
     }
 }
 
 cout << ret << endl;
 return 0;
}