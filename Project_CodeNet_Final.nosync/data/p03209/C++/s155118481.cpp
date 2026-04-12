#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll rec(ll n, ll x){
  if(n==0) return 1;
  ll len = pow(2,n+2) - 3;
  ll pty = pow(2,n+1) - 1;
  if(x==1) return 0;
  else if(x<=(len+1)/2-1) return rec(n-1,x-1);
  else if(x==(len+1)/2) return (pty-1)/2 + 1;
  else if(x<=len-1) return (pty-1)/2 + 1 + rec(n-1, x-(pow(2,n+1)-3)-2);
  else return pty;
}

int main() {
  ll n,x; cin >> n >> x;
  cout << rec(n,x) << endl;
}

