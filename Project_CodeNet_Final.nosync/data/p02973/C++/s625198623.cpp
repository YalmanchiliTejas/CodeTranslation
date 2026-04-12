
#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin >> n;
  multiset<ll> s;
  rep(i,n){
      ll tmp ;cin >> tmp;
      auto it = s.lower_bound(tmp);
      if(it==s.begin()){
          s.insert(tmp);
      }else{
          it--;
          s.erase(it);
          s.insert(tmp);
      }
  }
  cout << s.size() << endl;
}