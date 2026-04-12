#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l; i<(int)(r); i++)
#define rep_eq(i,l,r) for(int i=l; i<=(int)(r); i++)
#define all(vec) vec.begin(),vec.end()
#define allr(vec) vec.rbegin(),vec.rend()
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll=int64_t;

using vb=vector<bool>;
using vc=vector<char>;
using vs=vector<string>;
using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int A,B,C,X,Y; cin >>A >>B >>C >>X >>Y;

  int ans=0;
  if (2*C<A+B) {
    int Z=min(X,Y);
    X-=Z;
    Y-=Z;
    ans+=2*C*Z;
  }
  A=min(A,2*C);
  B=min(B,2*C);
  ans+=A*X;
  ans+=B*Y;

  cout <<ans <<'\n';
  return 0;
}
