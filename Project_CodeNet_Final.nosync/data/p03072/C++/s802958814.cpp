#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

//#include <tuple>

//#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long
#define pb push_back

int main() {
  int N, H;
  int cnt = 0; // 最初の山は必ず見える
  int max_mount = 0;

  cin >> N;
  rep(i, N){
    cin >> H;
    if (max_mount <= H) cnt++;
    max_mount = max(max_mount, H);

  }
  
  cout << cnt << endl;

}
