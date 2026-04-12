//Compete against Yourself.
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
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

int n, a[N], m;
string s, t;

int32_t main(){_
      
   cin >> n >> m;

   if (n == m){
      cout<<"Yes";
   }
   else{
      cout<<"No";
   }
   

   return 0;
}