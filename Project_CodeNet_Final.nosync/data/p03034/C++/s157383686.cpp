//Link : https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_f

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

int s[N];

void solve() {
  int n;scanf("%d ", &n);
  for(int i=0;i<n;++i) {
    scanf("%d ", &s[i]);
  }
  ll ret = 0;
  for(int d=1;d<n;++d) {
    int l = d, r= n-d-1;
    ll tmp = 0;
    while(l<n && r>=0) {
      tmp += s[l] + s[r];
      if(r<=d) {
        break;
      }
      if(r%d!=0)
        ret = max(ret,tmp);
      if(r%d==0) {
        int a = r;
        int k = (n-1-r)/d;
        if(k*d<a) {
          ret = max(ret,tmp);
        }
      }
      l +=d,r -= d;
    }
  }
  printf("%lld\n", ret);
}

int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
