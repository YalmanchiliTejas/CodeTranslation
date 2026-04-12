#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end());
#define VREV(v) reverse(v.begin(), v.end());
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vdouble = vector<double>;
using vstr = vector<string>;
typedef pair<int,int> P;
int dx[4] = {1, 0, -1, 0},dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
template<class T> inline bool chmax(T& a, T b){if(a<b) {a=b; return 1;} return 0; }
template<class T> inline bool chmin(T& a, T b){if(a>b) {a=b; return 1;} return 0; }
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#include <iostream>

using namespace std;

int main() {
   int n,k;

   string s;
   cin>>n>>s>>k;
   char o=s[k-1];
   rep(i,s.length())
    if(s[i]==o)
     cout<<s[i];
     else
     {
       cout<<"*";
     }
     


   return 0;
}