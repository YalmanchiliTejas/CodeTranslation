#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
const int N = 1000000;

int main() {
   string s; cin >> s;
   
   if((s[0] == 'A' && s[1] == 'A' && s[2] == 'A') ||(s[0] == 'B' && s[1] == 'B' && s[2] == 'B'))print("No");
   else print("Yes");
}