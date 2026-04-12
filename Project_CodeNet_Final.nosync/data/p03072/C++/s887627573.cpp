#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
#define print(x) cerr << (#x) << "is "<< x << "\n"
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,x; 
   cin >> n;
   set<pii> s;
   int ans = 0;
   f(i,0,n){
      cin >> x;
      s.insert({x,i});
      auto k = s.find({x,i});
      k++;
      if(k==s.end()) ans++;
   }
   cout << ans << '\n';
   return 0;
}