#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

ll n, x;
vector<ll> h(55), p(55);

ll dfs(ll cur)
{
  ll ret = 0;
  //cout << cur << " " << x << " / " << h[cur] << endl;
  
  if(cur == 0)
  {
    ret++;
  }
  else if(x == 1)
  {
    //none
  }
  else if(x <= h[cur-1] + 1)
  {
    x--;
    ret += dfs(cur-1);
  }
  else if(x == h[cur-1] + 2)
  {
    ret += p[cur-1] + 1;
  }
  else if(x <= h[cur] - 1)
  {
    x -= h[cur-1] + 2;
    ret += p[cur-1] + 1;
    ret += dfs(cur-1);
  }
  else if(x == h[cur])
  {
    ret += p[cur];
  }
  
  return ret;
}


int main()
{
  cin >> n >> x;
  p[0] = 1;
  rep(i, n) p[i+1] = p[i]*2+1;
  h[0] = 1;
  rep(i, n) h[i+1] = h[i]*2+3;
  
  cout << dfs(n) << endl;

  return 0;
}