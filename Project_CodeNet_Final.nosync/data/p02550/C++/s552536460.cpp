#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
#define float long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define endl '\n'
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define min3(a,b,c) min(a, min(b, c))
#define max3(a,b,c) max(a, max(b, c))
#define all(x) x.begin(), x.end()
#define fill(a,b) memset(a, b, sizeof(a))
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
vector<int> v;
map<int,int> pos;

signed main()
{
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,x,m; cin>>n>>x>>m;
    while(pos[x]==0){
    	v.pb(x);
    	pos[x]=sz(v);
    	x=(x*x)%m;
    }
	if(sz(v)>=n){
    	int ans=0;
    	for(int i=0;i<n;i++) ans+=v[i];
    	cout<<ans<<endl;
    	return 0;
    }
    int a=0,b=0;
    for(int i=0;i<sz(v);i++){
    	if(i<pos[x]-1) a+=v[i];
    	else b+=v[i];
    }
    int ans=a+b*((n-pos[x]+1)/(sz(v)-pos[x]+1));
    for(int i=0;i<((n-pos[x]+1)%(sz(v)-pos[x]+1));i++) ans+=v[i+pos[x]-1];
    cout<<ans<<endl;

}