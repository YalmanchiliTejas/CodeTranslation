#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define r_rep(i, n) for(int i = (int)n-1; i >= 0; i--)
#define ll long long int
#define pb push_back
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main() {
  int a, b, c, x, y, sum = 0;
  cin >> a >> b >> c >> x >> y;
  int z = min(x, y);
  int w = max(x, y);

  if(a+b < c*2){
    sum += a*x + b*y;
  } else {    
    sum += c*2*z;
    x -= z;
    y -= z;
    int left = x*a + y*b;
    if((w-z)*c*2 < left){
      sum += (w-z)*c*2;
    } else {
      sum += left;
    }
  }
  print(sum);
}
