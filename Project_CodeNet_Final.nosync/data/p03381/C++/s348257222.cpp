#include <bits/stdc++.h>

#define mk make_pair
#define sc second
#define fr first
#define pb emplace_back
#define all(s) s.begin(), s.end()
#define sz(s) ( (int)s.size() )

using namespace std;

const int inf = (int)1e9 + 7;
const int N = (int)3e5 + 7;

int n;
int a[N];
int ans[N];
vector <pair<int,int> > v;

main () {
      cin >> n;

      for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            v.pb(mk(a[i],i));
      }
      sort (v.begin(),v.end());

      int x = v[(n / 2)].fr;
      int y = v[(n / 2) - 1].fr;

      for (int i = 0; i < v.size(); i ++) {
            if (n / 2 > i)
                  ans[v[i].sc] = x;
            else
                  ans[v[i].sc] = y;
      }
      for (int i = 1; i <= n; i ++)
            cout << ans[i] << endl;
}
