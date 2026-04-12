#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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



int main() {
  ll n,k;
  scanf("%lld%lld", &n,&k);
  ll ans = 0;

  FOR(i,1,n){
    ll a = n/i;
    ll b = n%i;

    if(k!=0){

    ans += max(i-k,(ll)0) * a;
    ans += max(b-k+1,(ll)0);

    }

    else{
      ans = n*n;
    }

    // cout << ans << endl;
  }

  cout << ans << endl;

}

