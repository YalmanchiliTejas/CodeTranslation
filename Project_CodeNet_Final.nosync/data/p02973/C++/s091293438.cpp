#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 5*(int)1e5 + 10;

int n;

// strictly-increasing LIS in nlogn
/*
   in case of longest nondecreasing sequences
   change lower_bound to upper_bound
*/
vector<int> a;
int lis(){
   vector<int> v;
   for (int i = 0; i < n; i++) {
       auto it = upper_bound(v.begin(), v.end(), a[i]);
       if (it != v.end()) *it = a[i];
       else v.push_back(a[i]);
   }
   return (int)v.size();
}

int32_t main(){_

   cin>>n;

   a.resize(n);
   
   for(auto &i: a)
      cin >> i;
   
   reverse(a.begin(), a.end());

   cout<<lis();
   

   return 0;
}