#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> v;
  int a;
  cin >> a;
  v.push_back(a);
  rep(i, N-1) {
    int temp;
    cin >> temp;
    int ind = lower_bound(v.begin(), v.end(), temp) - v.begin();
    if(ind == 0) v.insert(v.begin(), temp);
    else v[ind-1] = temp;
  }
  cout << v.size() << endl;
  return 0;
}