#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int n,g,b; cin >> n >> g >>b;
   int m = n * 100 + g * 10 + b;
   cout << ((0 == (m % 4)) ? "YES" : "NO");
   return 0;
}