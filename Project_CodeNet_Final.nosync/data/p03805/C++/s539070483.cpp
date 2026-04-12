#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

typedef long long ll;
typedef pair<int,int> p;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<p> v(m, {0, 0});
  for (int i = 0; i < m; i++)
  {
    cin >> v[i].first >> v[i].second;
  }

  vector<int> node(n, 0);
  for(int i = 0; i < n; i++) node[i] = i;
  int res = 0;

  do{
    if(node[0] != 0) continue;
    bool flag = true;
    // for(auto a : node)cout << a;
    // cout << endl;
    for (int i = 0; i < n-1; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if((node[i] == v[j].first-1 && node[i+1] == v[j].second-1) || (node[i] == v[j].second-1 && node[i+1] == v[j].first-1))
          break;
        if(j == m-1) flag = false;
      }
    }
    if(flag) {
      res++;
      // for(auto a : node)cout << a;
    }
  } while(next_permutation(all(node)));

  cout << res << endl;
}