/*
ID: Aman Raj
LANG: C++
TASK: subset
*/
#include<iostream>
#include <stdio.h>
//#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<math.h>
typedef  long long int ll;
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
//hr
using namespace std;
using namespace __gnu_pbds;
//hy
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
//#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
//#define flush fflush(stdout)
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <fstream>
// find_by_order()  // order_of_key
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;
  //# define mod 1e9+7
   ll gcd(ll a,ll b)
   {
       if(a==0)return b;
       return gcd(b%a,a);
   }
//kj
int main()
{
   ll n;cin>>n;
     vector<ll> v(n);
      vector<ll> dp(n,0);
      for(ll i=0;i<n;i++)cin>>v[i];
      ll ans=0;
     vector<ll> s;
     for(ll i=n-1;i>=0;i--)
     { //cout<<i<<" ";
          ll a=v[i];
         auto iter=upper_bound(s.begin(),s.end(),a);
         if(iter==s.end())
         { ans++;
           s.push_back(a);

         }
         else *iter=a;
     }

      cout<<ans;

      return 0;
}
