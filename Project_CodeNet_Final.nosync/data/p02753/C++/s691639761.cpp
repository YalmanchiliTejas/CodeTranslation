 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;

 int main() {
   string s;
   cin >> s;
   string res="Yes";
   if (s == "AAA" || s == "BBB") {
     res = "No";
   }
   cout << res << '\n';
 }
