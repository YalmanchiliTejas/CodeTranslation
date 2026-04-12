#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define pd pair<double, double>
#define vp vector<pi>
#define f(i, n) for(int i = 0; i < n; i++)
#define fo(i, a, n) for(int i = a; i < n; i++)
#define mod (1000*1000*1000+7)
#define sz(x) int((x).size())
#define all(x) x.begin(),x.end()
#define DBG(v) cerr << #v << " = " << (v) << endl;
ll INF = (1ll<<61);

using namespace std;

ll n, m;

vi dp(300000, -1);

ll fact(ll x){
  if(x == 0) return 1;
  if(dp[x] != -1) return dp[x];
  return dp[x] = (fact(x-1) * x)%m;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >>  n >> m;
    if(n==m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
