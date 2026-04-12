
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

ll vs[100000+10];
int n;

int visited[100000+10];
// bool isOK1(ll ab, int i) {
//   ll a = n-1 - ab*i;
//   ll b = a - ab;
//   if(a <= 0 || b <= 0) return false;
// }

// int visited2[100000+10];
// int counter2;
// bool isOK2(ll ab, int i) {
//   ++counter2;
//   ll a = n-1 - ab*i;
//   ll b = a - ab;
//   if(a <= 0 || b <= 0) return false;
//   visited2[0] = counter2;
//   for(int pos = 0; ; ) {
//     pos += a;
//     if(pos >= n) return false;
//     if(visited2[pos] == counter2) return false;
//     visited2[pos] = counter2;
//     if(pos == n-1) {
//       return true;
//     }
//     pos -= b;
//     if(pos < 0) return false;
//     if(visited2[pos] == counter2) return false;
//     visited2[pos] = counter2;
//   }
// }

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lld", &vs[i]);
  }

  ll res = 0;
  for(int ab = 1; ab < n-1; ++ab) {
    ll leftSum = 0;
    ll rightSum = 0;
    for(int i = 1; ab*i < n && n-1-ab*i >= 0; ++i) {
      ll a = n-1 - ab*i;
      ll b = a - ab;
      if(a <= 0 || b <= 0) break;
      if(visited[ab*i] == ab) break;
      visited[ab*i] = ab;
      if(visited[n-1-ab*i] == ab) break;
      visited[n-1-ab*i] = ab;
      // bool x1 = isOK1(ab, i);
      // bool x2 = isOK2(ab, i);
      // if(x1 != x2) {
      //   ll a = 
      //   ll b = a - ab;
      //   cerr << "> " << x1 << " " << x2 << " " << ab << " " << i << " " << a << " " << b << " " << ab*i << " " << n-1-ab*i << endl;
      // }
      // if(!x2) break;
      leftSum += vs[ab*i];
      rightSum += vs[n-1-ab*i];
      res = max(res, leftSum + rightSum);
    }
  }
  cout << res << endl;
  return 0;
}
