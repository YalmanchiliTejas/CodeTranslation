#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
  int n, k;
  string s;
  cin >> n >> s >> k;
  char c = s.at(k - 1);
  rep(i,n){
    if(s.at(i)!=c){
      s.at(i) = '*';
    }
  }
  cout << s << endl;
  return 0;
}