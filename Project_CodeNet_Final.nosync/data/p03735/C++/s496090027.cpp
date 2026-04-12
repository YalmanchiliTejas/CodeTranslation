# include <bits/stdc++.h>
# define f first
# define s second

using namespace std;

const int N = 1e6;

long long n, x, y, ans;
pair <long long, long long> a[N], b[N];

int main(){
      scanf("%lld", &n);
      for(int i = 1;i <= n;i ++){
             scanf("%lld %lld", &a[i].f, &a[i].s);
             if(a[i].f > a[i].s)
                 swap(a[i].s, a[i].f);
             b[i].f = a[i].s, b[i].s = a[i].f;
      }

      sort(b + 1, b + n + 1);
      sort(a + 1, a + n + 1);

      ans = (a[n].f - a[1].f) * (b[n].f - b[1].f);
      long long r = a[n].f, l = 1e9;
      for(int i = 1;i < n;i ++){
             l = min(a[i].s, l);
             r = max(r, a[i].s);
             ans = min(ans, (b[n].f - a[1].f) * (r - min(l, a[i + 1].f)));
      }
      cout << ans;
}
