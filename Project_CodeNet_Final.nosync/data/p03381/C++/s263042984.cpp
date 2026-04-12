#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



int main (int argc, char*argv[]) {
  int n;
  cin >> n;
  vector<pair<int,int>> a ;
  for(int i=0; i<n; i++) {
    int value;
    cin >> value;
    a.push_back(make_pair(value, i));
  }
  sort(a.begin(), a.end());

  vector<pair<int,int>> ans;
  int l = a[n/2-1].first;
  int r = a[n/2].first;

  for(int i=0; i<n; i++) {
    if(i * 2 < n) {
      ans.push_back(make_pair(a[i].second, r));
    } else {
      ans.push_back(make_pair(a[i].second, l));
    }
  }

  sort(ans.begin(), ans.end());
  for(auto elem : ans) {
    cout << elem.second << endl;
  }
  return 0;
}