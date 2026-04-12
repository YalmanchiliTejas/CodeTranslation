
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 200000;
int N;
int a[MAX_N];
int ans[MAX_N];

int main() {
  cin >> N;
  rep(i,N) cin >> a[i];

  vector<pii> v;
  for (int i = 0; i < N; ++i) {
    v.push_back(pii(a[i], i));
  }

  sort(all(v));

  for (int i = 0; i < N; ++i) {
    if (i < N/2) {
      ans[v[i].sc] = v[N/2].fi;
    } else {
      ans[v[i].sc] = v[N/2-1].fi;
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << endl;
  }

}
