#include<bits/stdc++.h>
using namespace std;
#define int 		long long
#define ull 		unsigned long long
#define vi 			vector<int>
#define vvi			vector<vi>
#define pb			push_back
#define mii  		map<int, int>
#define pii 		pair<int, int>
#define pq 			priority_queue<int>
#define pqs 		priority_queue<int, vi, greater<int>>
#define mod 		1000000007
#define inf 		1e18
#define ps(x, y) 	fixed<<setprecision(y)<<x
#define w(t)		int t; cin>>t; while(t--)
#define rep(i,a,b)	for(int i = a; i < b; i++)
#define repd(i,a,b)	for(int i = a; i>= b; i--)
int32_t main()
{
	int n, x, m, a;
    cin>>n>>x>>m;
    vector<int> v;
    a = x%m;
    int ans = 0;
    rep(i, 0, n)
    {
        if(find(v.begin(), v.end(), a) != v.end())
            break;
        ans += a;
        v.pb(a);
        a = (a*a)%m;
        if(i == n-1)
        {
            cout<<ans;
            return 0;
        }
    }
    int p = find(v.begin(), v.end(), a) - v.begin();
    int count = 0, s = v.size();
    ans = 0;
    rep(i, 0, p)
    {
        ans += v[i];
        n--;
    }
    a = 0;
    rep(i, p, s)
        a = a+v[i];
    ans += a*(n/(s - p));
    count = n%(s - p);
    int i = p;
    while(count--)
        ans += v[i++];
    cout<<ans;
	return 0;
}