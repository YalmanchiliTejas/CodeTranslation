#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (ll)1e16
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=2e5+5;
ll t[4*N],lazy[4*N];

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
	int n,m;
	cin>>n>>m;
	vpii segl[n+2];
	vpii segr[n+2];
	int l,r,a;
	fr(i,1,m+1){
		cin>>l>>r>>a;
		l++;r++;
		segl[l].pb({l-1,a});
		segr[r].pb({l-1,-a});
	}
	vll dp(n+3,0);
	n++;
	update(1,1,n,1,1,0);
	fr(i,2,n+1){
		for(auto pp: segl[i]){
			update(1,1,n,1,pp.first,pp.second);
		}
		dp[i]=query(1,1,n,1,i-1);
		if(dp[i]==-INF){
			dp[i]=0;
		}
		for(auto pp: segr[i]){
			update(1,1,n,1,pp.first,pp.second);
		}
		update(1,1,n,i,i,dp[i]);
	}
	ll ans=0;
	fr(i,1,n+2){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}