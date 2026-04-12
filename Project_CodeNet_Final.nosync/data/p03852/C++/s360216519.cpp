#include <bits/stdc++.h>
using namespace std;

#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)a.size())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  char c;
  scanf(" %c", &c);
  if (string("aeiou").find(c) != string::npos) {
    puts("vowel");
  } else {
    puts("consonant");
  }
  return 0;
}

