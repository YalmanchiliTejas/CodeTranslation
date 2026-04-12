#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define vecsort(x) sort(x.begin(), x.end())
#define vecrsort(x) sort(x.rbegin(), x.rend())
#define massort(x, n) sort(x, x + n)
#define FOR(i, n) for(int i = 0; i < n; i ++)
using namespace std;
int max(int32_t a, int b){
   return max((int)a, b);
}

const int INF = 1e12;

int bin_search(vector<int> &v, int elem){
   int l = 0;
   int r = v.size();
   while(l < r){
      int m = (l + r) / 2;
      if(v[m] < elem)
         r = m;
      else
         l = m + 1;
   }
   if(r == v.size())
      return INF;
   return l;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n; cin >> n;
   vector<int> ar(n);
   for(int i = 0; i < n; i ++)
      cin >> ar[i];
   vector<int> ans;
   for(int i = 0; i < n; i ++){
      int x = bin_search(ans, ar[i]);
      if(x == INF){
         ans.pb(ar[i]);
      }else{
         ans[x] = ar[i];
      }
   }
   cout << ans.size();
}
