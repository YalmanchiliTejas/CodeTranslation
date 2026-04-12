#include<bits/stdc++.h>
#define MSET(x,y) memset(x,y,sizeof(x))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 100005
#define ll long long
#define ld long double
#define INF 1e18
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll MOD = 1000000007;
string yes = "Yes\n";
string no = "No\n";

int32_t main() {
  fastio;
  #ifndef ONLINE_JUDGE
  freopen("i.txt", "r", stdin);
  freopen("o.txt", "w", stdout);
  #endif
  ll x;
  cin>>x;
  if(x>=30) {
    cout<<yes;
  } else cout<<no;
}