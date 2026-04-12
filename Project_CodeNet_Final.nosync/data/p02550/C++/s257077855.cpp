#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int vis[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,x,m;
   cin >> n >> x >> m;
   vector<int> A;
   A = {x};
   for(int i = 1; i < n and !vis[x]; ++i){
      vis[x] = 1;
      x = (x*x)%m;
      A.push_back(x);
   }   
   if(A.size() == n){
      int sm = 0;
      for(int i : A){
         sm += i;
      }
      cout << sm << '\n';
      return 0;
   }
   int occuring = A.back();
   A.pop_back();
   int sm = 0;
   for(int i : A){
      sm += i;
   }
   int pos = -1;
   for(int i = 0; i < A.size(); ++i){
      if(A[i] == occuring){
         pos = i;
         break;
      }
   }
   debug(pos);
   vector<int> rem;
   int lft = n-(int)A.size();
   int sz = (int)A.size()-pos;
   int dv = lft/sz;
   int trm = lft%sz;
   int tot = 0;
   for(int i = pos; i < A.size(); ++i){
      rem.push_back(A[i]);
      tot += A[i];
   }
   tot *= dv;
   for(int i = 0; i < trm; ++i){
      tot += rem[i];
   }
   tot += sm;
   cout << tot << '\n';
   return 0;
} 