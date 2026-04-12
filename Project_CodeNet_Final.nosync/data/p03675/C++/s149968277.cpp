# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e6 + 5;

typedef long long ll;

int n, a[N];
vector <int> ans;

int main()
{
      cin >> n;

      for(int i = 1; i <= n; i ++)
            cin >> a[i];

      int i;
      for(i = n; i >= 1; i -= 2)
            ans.pb(a[i]);
      if(n % 2) i = 2;
      else i = 1;
      for(; i <= n; i += 2)
            ans.pb(a[i]);
      for(int to : ans)
            cout << to << " ";
}
