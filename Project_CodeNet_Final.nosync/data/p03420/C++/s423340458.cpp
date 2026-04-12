#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
int main(void)
{
    int n,k;
    cin>>n>>k;
    if (!k) {
    	cout << 1ll * n * n << '\n';
    	return 0;
    }
    ll ans = 0;
    for (int i = k;i <= n;++i) {
    	int t = (n + 1) / i;
    	ans += 1ll * (i - k) * t;
    	int l = i * t + k;
    	int r = n;
    	ans += max(0,r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}