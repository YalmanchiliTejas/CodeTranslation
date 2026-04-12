//$ darklife_12
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <cstring>
#include <bits/stdc++.h>
#include <iostream>
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define enterarray(a,n) for(int i=0;i<(int)(n);++i)cin>>a[i];
#define ins insert
const int MOD =998244353;
const int MX = int(2e6+9);
using namespace std;
int even(ll num){
    if(num%2==0)return 1;
    else return 0;
}
void printvector(vector<int> v){
    int i;
    for0(i,v.size())cout<<v[i]<<" ";
}
void solve()              
{
    ll n,m,i,j,k;
    long long a[200005],b[200005];
    ll ans=0,res;
    bool flag=true;
    vector<int> v;
    string s1,s2;
    set<int> s;
    cin>>n;
    if(n>=30)cout<<"Yes";
    else cout<<"No";
}
 
int main()
{
    FAST;
   int t;
    t=1;
    while(t--)
    {
        solve();
       cout<<"\n";
    }
}