/*
ID: Aman Raj
LANG: C++
TASK: preface
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

using namespace std;
using namespace __gnu_pbds;

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

	   //vector<ll > vten(7),vfive(7),vfifty(7),vhundred(7),vfivehundred(7),vthousand(7);
	   //# define INF 1000000;
vector<vector<pair<ll,ll>> > dpl;
vector<ll> v;
pair<ll,ll> aman(ll j,ll i)
{  if(dpl[j][i].first==-1)
        { if(i==j){dpl[j][i]={v[j],0};}
          else
            { pair<ll,ll> a=aman(j+1,i);
            (v[i]+dpl[j][i-1].second>=v[j]+a.second) ? dpl[j][i]={v[i]+dpl[j][i-1].second,dpl[j][i-1].first}:dpl[j][i]={v[j]+a.second,a.first};
            }

        }

             return dpl[j][i];
}
int main()
{
    ll n;cin>>n;
      v.resize(n,0);
       for(ll i=0;i<n;i++)cin>>v[i];

        vector<pair<ll,ll> > dp(n+1);
        dp[0]=(make_pair(0,0));
        dpl.resize(n,vector<pair<ll,ll> >(n,{-1,-1}));
        for(ll i=1;i<=n;i++)
        {
              dp[i]=make_pair(v[i-1]+dp[i-1].second,dp[i-1].first);
              if(i>1){
                    pair<ll,ll> m=aman(1,i-1);

                     v[i-1]+dp[i-1].second>=m.second+v[0]  ?dp[i]=make_pair(v[i-1]+dp[i-1].second,dp[i-1].first) :dp[i]={v[0]+m.second,m.first};
                     }

        }
        cout<<dp[n].first-dp[n].second;


	return 0;

}
