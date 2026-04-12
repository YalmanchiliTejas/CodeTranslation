#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;
typedef pair<int, int> P;

#define MAX 100005
#define INF 1001001001

int main(int, char**)
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> ans;
  int q;
  cin >> q;
  rep(i,q) {
    int k; cin >> k;
    auto itr = lower_bound(a.begin(), a.end(), k);
    ans.push_back(itr-a.begin());
  }

  for (auto a : ans) cout << a << endl;

  return 0;
}

