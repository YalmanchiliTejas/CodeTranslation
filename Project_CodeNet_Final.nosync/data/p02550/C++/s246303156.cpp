#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define all(v) v.begin(), v.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pll pair<long long, long long>
#define pb emplace_back
#define mp make_pair
#define mt make_tuple
#define vc vector<char>
#define vvc vector<vc>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
template <class T>bool chmax(T &a, const T &b){if (a < b){a = b;return 1;}return 0;}
template <class T>bool chmin(T &a, const T &b){if (b < a){a = b;return 1;}return 0;}
//snippets:tmp,cl,cvl,cs,co,coy,con,cov,setp

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll x;
  cin >> x;
  ll m;
  cin >> m;
  ll c=1;
  vll d(m+10);
  ll count=0;
  ll sum=0;
  vll s(m+10);
  while(true){
    if(count!=0) c=c*c%m;
    else c=x%m;
    if(d[c]!=0) break;
    count++;
    d[c]=count;
    sum=sum+c;
    s[count]=sum;
    if(count==n){
      cout<<sum<<endl;
      return 0;
    }
  }
  ll ans=0;
  ll sum2=s[count]-s[d[c]-1];
  ans=sum+sum2*((n-count)/(count-d[c]+1));
  ans+=s[d[c]-1+(n-count)%(count-d[c]+1)]-s[d[c]-1];
  cout<<ans<<endl;
}
