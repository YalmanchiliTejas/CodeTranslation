#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int n;
  cin >> n;

  vector<int> h(n);
  int max_h = 0; int count = 0;
  rep(i, n) {
      cin >> h[i];
      if (max_h <= h[i]) 
      {
          max_h = h[i];
          count++;
      }
  }
  cout << count << endl;
}