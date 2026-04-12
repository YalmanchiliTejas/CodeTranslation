#include <bits/stdc++.h>
// #include "bits/stdc++.h"

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;

int main() {
  int n;
  while(cin >> n && n > 0){
    int s[n];
    int sum = 0,large = 0,small = 1000;

    rep(i,0,n){
      cin >> s[i];
      sum += s[i];
      if(large < s[i]) large = s[i];
      if(small > s[i]) small = s[i];
    }
    pout((sum -large-small)/(n-2));
  }
  return 0;
}
