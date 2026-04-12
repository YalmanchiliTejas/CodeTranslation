#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define OR(x,y,z) set_union((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> VECINT;
typedef vector<ll> VECLL;

int main() {
  int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
  int ans = A*X+B*Y;
  if (X>Y) {
    ans = min(ans, C*2*X);
    ans = min(ans, C*2*Y+A*(X-Y));
  } else {
    ans = min(ans, C*2*Y);
    ans = min(ans, C*2*X+B*(Y-X));
  }
  OUT(ans);

  return 0;
}