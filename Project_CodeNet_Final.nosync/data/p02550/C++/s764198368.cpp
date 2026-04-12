#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool vis[100005];
ll pre[100005];
long pos[100005];

int main()
{
  ll n,x,m; cin>>n>>x>>m;

  vis[x] = true;
  ll prev = x;
  pre[1] = x;
  pos[x] = 1;


  ll i = 2;
  ll ans = 0;

  if(n>1)
  {
    while(1)
    {
      ll cur = (prev * prev) % m;

      if(vis[cur])
      {
        long pos_cur = pos[cur];
        long seg_val = pre[i-1] - pre[pos_cur - 1];

        ans = pre[pos_cur - 1];
        ll sz = n - (pos_cur - 1);
        ll seg_size = i - pos_cur;
        ll q = sz/seg_size;
        ll part = sz % seg_size;

        ans += (q * seg_val);
        if(part)
          ans += (pre[pos_cur + (part-1)] - pre[pos_cur -1]);
        break;
      }
      else
      {
        vis[cur] = true;
        pos[cur] = i;
        pre[i] = cur + pre[i-1];
        i++;
        prev = cur;
      }
      if(i>n)
      {
        ans = pre[i-1];
        break;
      }
    }
  }

  cout<<((n == 1)? x: ans);
  return 0;
}