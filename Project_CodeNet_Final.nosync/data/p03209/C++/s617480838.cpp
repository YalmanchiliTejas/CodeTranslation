#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
/*
#include <map>
#include <functional>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
*/
using namespace std;
typedef long long ll;
//typedef pair<ll, ll> P;

/* Union-find
int par[100010];
int trank[100010];

void init(int n) {
   for (int i=0;i<n;i++) {
      par[i] = i;
      trank[i] = 0;
   }
}
int find(int x) {
   if (par[x] == x) {
      return x;
   } else {
      return par[x] = find(par[x]);
   }
}
void unite(int x, int y) {
   x = find(x);
   y = find(y);
   if (x == y) return;
   if (trank[x] < trank[y]) {
      par[x] = y;
   } else {
      par[y] = x;
      if (trank[x] == trank[y]) trank[x]++;
   }
}
bool same(int x, int y) {
   return find(x) == find(y);
}
*/

ll N, X;
ll had_p;
ll ep[70];
ll fp[70];

ll rec(ll Y, int i) {
   if (i <= 0) {
      return (Y > 0) ? 1 : 0;
   }
   Y--;
   if (Y == 0) {
      return 0;
   }

   if (Y < fp[i-1]) {
            //cout << "case1" << endl;
      return rec(Y, i-1);
   }
   Y -= fp[i-1];
   if (Y == 0) {
      //cout << "case2" << endl;
      return ep[i-1];
   }
   Y--;
   if (Y == 0) {
      //cout << "case3" << endl;
      return ep[i-1] + 1;
   }

   if (Y < fp[i-1]) 
   {
      //cout << "case4" << endl;
      return rec(Y, i-1) + ep[i-1] + 1;
   }
   //cout << "case5" << endl;
   return ep[i-1] + 1 + ep[i-1];
}

int main() {
   cin >> N >> X;
   ep[0] = 1;
   fp[0] = 1;
   for (int i=1;i<=N-1;i++) {
      ep[i] = ep[i-1] + 1 + ep[i-1];
      fp[i] = 1 + fp[i-1] +1 + fp[i-1] + 1;
   }
   cout << rec(X, N) << endl;
}