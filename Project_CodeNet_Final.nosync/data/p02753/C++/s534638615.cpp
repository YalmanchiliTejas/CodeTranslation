#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;


int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i, s.size()) mp[s[i]]++;
  string ans = "No";
  if (mp['A'] > 0 and mp['B'] > 0) ans = "Yes";
  cout << ans << endl;
  return 0;
}