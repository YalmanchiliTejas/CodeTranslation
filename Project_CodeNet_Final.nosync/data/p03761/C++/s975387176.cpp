#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i,n) for(int i=0;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a) (a).begin(),(a).end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int a[26];
  int b[26];
  for(int i = 0; i < 26; i++){
      a[i] = 1e9;
      b[i] = 0;
  }
  for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      for(int i = 0; i < s.size(); i++){
          b[s[i] - 'a']++;
      }
      for(int i = 0; i < 26; i++){
          a[i] = min(a[i],b[i]);
      }
      for(int i = 0; i < 26; i++){
          b[i] = 0;
      }
  }
  for(int i = 0; i < 26; i++){
      for(int j = 0; j < a[i]; j++){
          cout << static_cast<char>('a' + i);
      }
  }
  cout << endl;
}
