#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;

int main(){

  int N, H;
  cin >> N;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> H;
    vec.at(i) = H;
  }

  
  for (int i = N-1; i >= 0; i--) {
    bool flag = true;
    for (int j = i; j >= 0; j--) {
      if(vec.at(i) - vec.at(j) < 0) flag = false;
      if(flag == false) break;
    }
    if(flag == true) ans++;
  }

  cout << ans << endl;

  return 0;
}