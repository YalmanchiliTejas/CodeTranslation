#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> num(26,50);
  vector<int> now(26,0);
  int l,b;
  string S;
  for (int i=0; i<N; i++) {
    cin >> S;
    l = S.size();
    for (int j=0; j<l; j++) {
      now[S[j] - 'a']++;
    }
    for (int j=0; j<26; j++) {
      num[j] = min(num[j],now[j]);
      now[j] = 0;
    }
  }
  char p;
  for (int i=0; i<26; i++) {
    p = 'a' + i;
    for (int j=0; j<num[i]; j++) {
      cout << p;
    }
  }
  cout << endl;
}