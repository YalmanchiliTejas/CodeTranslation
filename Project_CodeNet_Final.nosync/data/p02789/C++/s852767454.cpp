#include<bits/stdc++.h>

#define ff first
#define endl "\n"
#define ss second
using namespace std;
#define maxn 2000006
#define pb push_back
#define ll long long
#define lll __int128
#define vll vector<ll>
#define mll map<ll,ll>
#define MOD 1000000007
#define pll pair<ll,ll>
#define ull unsigned long long
#define f(i,x,n) for(ll i=x;i<=n;i++)
#define fr(i,x,n) for(ll i=x;i>=n;i--)
inline ll min(ll a, ll b, ll c) { return min(min(a, b), c);}
inline ll max(ll a, ll b, ll c) { return max(max(a, b), c);}
inline void fastio(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};



int main(){
	fastio();

	int n,m; cin>>n>>m;
	if(m<n) cout<<"No";
	else cout<<"Yes";


	return 0;
}