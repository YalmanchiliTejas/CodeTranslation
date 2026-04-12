#ifdef __APPLE__
#include "bits:stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
auto scan = []{ static LL a; scanf("%lld", &a); return a;};



int main() {
  string s;
  getline(cin, s);
  for (LL i = 0; i < s.size() - 1; ++i) if(s[i] == 'A' && s[i+1] == 'C') return 0 * puts("Yes");
  puts("No");
}


/*
 4
 3
 0 0
 1 1
 1 2
 3
 1 2
 2 4
 4 8
 4
 1 1
 2 2
 3 3
 4 4
 5
 0 0
 2 0
 0 2
 2 2
 1 1
 
 */
