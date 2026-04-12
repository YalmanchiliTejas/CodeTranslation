#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 2*(int)1e5 + 10;

int n;
vector<vector<int>> v;

int32_t main(){_

   cin>>n;

   int x; 
   cin >> x;
   vector<int> vec;
   vec.pb(x);
   v.pb(vec);

   for (int i = 1; i < n; ++i)
   {
      cin >> x;
      int low = 0, high = sz(v)-1;
      int ans = -1;
      while(low <= high){
         int mid = (low + high) >> 1;
         if(v[mid].back() < x){
            ans = mid;
            high = mid - 1;
         }
         else{
            low = mid + 1;
         }
      }
      if(ans == -1){
         vector<int> vec;
         vec.pb(x);
         v.pb(vec);
      }
      else{
         v[ans].pb(x);
      }
   }

   cout<<sz(v);   

   return 0;
}