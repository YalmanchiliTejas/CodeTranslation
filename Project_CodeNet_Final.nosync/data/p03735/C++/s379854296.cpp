    #include<cstdio>
    #include<cstdlib>
    #include<cmath>
    #include<iostream>
    #include<string>
    #include<stack>
    #include<queue>
    #include<vector>
    #include<map>
    #include<set>
    #include<algorithm>
     
    #define rep(n) for(int i=0;i<n;i++)
    #define repp(j, n) for(int j=0;j<n;j++)
    #define reppp(i, m, n) for(int i=m;i<=n;i++)
    #define all(c) c.begin(), c.end()
    #define rall(c) c.rbegin(), c.rend()
    #define pb(x) push_back(x)
    #define eb(x, y) emplace_back(x, y)
    #define MOD 1000000007
    #define MAX 1000000001
    #define INF 1410065408
    #define EPS 1e-9
     
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> P;
    struct edge{int from, to; ll cost;};
     
    signed main(){
    	int n;
    	cin >> n;
    	vector<ll> x, y;
    	map<ll, ll> mx, my;
    	vector<P> xy;
    	rep(n){
    		ll xx, yy;
    		cin >> xx >> yy;
    		if(xx > yy) swap(xx, yy);
    		x.pb(xx);
    		y.pb(yy);
    		xy.eb(xx, yy);
    		mx[xx]++;
    		my[yy]++;
    	}
    	sort(all(xy));
    	
    	ll rmax = mx.rbegin()->first, rmin = mx.begin()->first;
    	ll bmax = my.rbegin()->first, bmin = my.begin()->first;
    	ll ans = (rmax - rmin) * (bmax - bmin);
    	
    	rep(n){
    		ll xx = xy[i].first, yy = xy[i].second;
    		mx[xx]--; mx[yy]++;
    		my[yy]--; my[xx]++;
    		if(mx[xx] == 0) mx.erase(xx);
    		if(my[yy] == 0) my.erase(yy);
    		rmax = mx.rbegin()->first, rmin = mx.begin()->first;
    		bmax = my.rbegin()->first, bmin = my.begin()->first;
    		ans = min(ans, (rmax - rmin) * (bmax - bmin));
    	}
    	cout << ans;
    }