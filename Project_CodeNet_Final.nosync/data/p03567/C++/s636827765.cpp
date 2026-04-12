#include <bits/stdc++.h>
using namespace std;
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int main(int argc, char *argv[])
{
  string s;
  cin >> s;

  for (int i = 0; i < s.size()-1; i++) {
    if(s[i]=='A'&&s[i+1]=='C') {puts("Yes");return 0;}
  }

  puts("No");
  return 0;
}
