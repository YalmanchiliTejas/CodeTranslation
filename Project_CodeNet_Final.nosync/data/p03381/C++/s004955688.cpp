#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,n) for(int i=s; i<n; ++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

typedef long long ll;
typedef pair<int, int> ii;

int main(){

  int n;
  cin >> n;
  vector<ii> x(n);
  vector<int> ans(n);
  rep(i, n){
    cin >> x[i].first;
    x[i].second = i;
  }

  SORT(x);

  rep(i, n){
    if(i < n / 2) ans[x[i].second] = x[n / 2].first;
    else ans[x[i].second] = x[n / 2 - 1].first;
    //cout << x[i].first << "\t" << x[i].second << endl;
  }

  rep(i, n) cout << ans[i] << endl;

	return 0;
}
