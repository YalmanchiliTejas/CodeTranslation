#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 200005;

int A[N], B[N];

int main() {
  int n;
  S(n);
  rep(i,0,n) {
    S(B[i]);
    A[i] = B[i];
  }
  sort(B, B + n);
  rep(i,0,n) {
    if(A[i] <= B[n / 2 - 1]) {
      P(B[n / 2]);
    } else {
      P(B[n / 2 - 1]);
    }
  }
  return 0;
}
