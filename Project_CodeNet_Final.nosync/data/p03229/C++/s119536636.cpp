#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end(),greater<ll>());

  if(n%2==0){
    ll res=0;
    for(int i=0;i<n/2; i++) res+=a[i]*2;
    res-=a[n/2-1]+a[n/2];
    for(int i=n/2+1; i<n; i++) res-=a[i]*2;
    cout << res << endl;
  }

  else{
    ll res1=0,res2=0;
    for(int i=0; i<n/2; i++) res1+=a[i]*2;
    res1-=a[n/2]+a[n/2+1];
    for(int i=n/2+2; i<n; i++) res1-=a[i]*2;

    for(int i=0; i<n/2-1; i++) res2+=a[i]*2;
    res2+=a[n/2-1]+a[n/2];
    for(int i=n/2+1; i<n; i++) res2-=a[i]*2;
    cout << max(res1,res2) << endl;
  }
  return 0;
}
