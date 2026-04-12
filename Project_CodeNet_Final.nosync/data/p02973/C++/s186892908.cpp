#include <bits/stdc++.h>
#define SORT(c) sort((c).begin(),(c).end())
#define db(x) cout<<#x<<"="<<x<<endl
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define reprs(i, m, n) for(int i = n; i >= m; i--)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;

int main(){

  int N;
  cin >> N;

  multiset<ll> se;
  int ct=0;
  ll a;
  rep(i,N){
    cin>>a;
    if(se.lower_bound(a)!=se.begin()){
      se.erase(prev(se.lower_bound(a)));
    }
    se.insert(a);
  }

  cout << se.size() <<endl;
  return 0;
}
