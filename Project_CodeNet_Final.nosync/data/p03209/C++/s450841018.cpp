#include <iostream>

#include <iomanip> // << fixed << precision(10)
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=s;i<t;i++)
#define REP(i,n) FOR(i,0,n)
#define PRINT(s) cout << s << "\n"
#define SORT(A) sort(A.begin(), A.end())
#define EACHPRINT(A, T) for_each(begin(A), end(A), [&](T i){ cout << i << " "; });cout << "\n"

typedef long lint;
typedef pair<lint, lint> P;

lint L(lint K, lint X, vector<lint> po) {
  if(K==0) return 1;
  if( X<= 1) return 0;
  if(X <= po[K-1]*4-2) return L(K-1, X-1, po);
  if(X <= po[K-1]*4-1) return L(K-1, X-2, po)+1;
  if(X <= po[K]*4-4) return L(K-1, X-(po[K-1]*4-1), po) + po[K]-1 + 1;
  return po[K+1]-1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    lint N; cin >> N;
    lint X; cin >> X;

    vector<lint> po;
    po.push_back(1);
    FOR(i,1,  N+2) {
      po.push_back(po[i-1]*2);
    }

    PRINT(L(N, X, po));
    return 0;
}
