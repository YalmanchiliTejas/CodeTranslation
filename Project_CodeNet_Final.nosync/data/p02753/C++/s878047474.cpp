
// Problem : A - Station and Bus
// Contest : AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_a
// Memory Limit : 1024.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i,n) for (ll i = 0; i < n; i++)
#define REPR(i,n) for(ll i = n-1; i >= 0; i--)
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define FORR(i,a,b) for(ll i = a-1; i>= b; i--)
#define ff first
#define ss second
#define MAXN (ll)1000002
#define MODN (ll)1000000007
#define mp make_pair
#define pb push_back
#define LN(x) (ll)x.length()
#define SZ(x) (ll)x.size()
#define bg(x) (x.begin())
#define rbg(x) (x.rbegin())
#define ENDL cout<<endl
ll n,t=1,tmp;
ll arr[MAXN];
int main() {
   string s;
cin>>s;
if(s[0] == s[1] && s[1] == s[2]) {
	cout<<"No";
} else cout<<"Yes";
}