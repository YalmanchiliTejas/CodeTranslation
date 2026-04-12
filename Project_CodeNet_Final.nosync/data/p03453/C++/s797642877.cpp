#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))

using ll = long long;

using namespace std;

 

constexpr ll inf = ll(1e18) + 9;

constexpr ll mod = ll(1e9) + 7;

vector<ll> dijkstra(vector<vector<pair<int, ll> > > const & g, int root) {

    vector<ll> dist(g.size(), inf);

    priority_queue<pair<ll, int> > que;

    dist[root] = 0;

    que.emplace(- dist[root], root);

    while (not que.empty()) {

        ll dist_i; int i; tie(dist_i, i) = que.top(); que.pop();

        if (dist[i] < - dist_i) continue;

        for (auto it : g[i]) {

            int j; ll cost; tie(j, cost) = it;

            if (- dist_i + cost < dist[j]) {

                dist[j] = - dist_i + cost;

                que.emplace(dist_i - cost, j);

            }

        }

    }

    return dist;

}






int start;
int goal;

ll dp1[100010],dp2[100010];

long long countup(vector<vector<int> > const & g, int root){
	if(root == goal){
		return 1;
	}
	if(g[root].size()==0){
		return 0;
	}
	if(dp2[root]!=0){
		return dp2[root];
	}
	long long cnt= 0;
	for(auto x:g[root]){
		cnt = (cnt+countup(g,x))%mod;
	}
	return dp2[root] = cnt;
}


long long countup2(vector<vector<int> > const & g, int root){
	if(root == start){
		return 1;
	}
	if(g[root].size()==0){
		return 0;
	}
	if(dp1[root]!=0){
		return dp1[root];
	}
	long long cnt= 0;
	for(auto x:g[root]){
		cnt = (cnt+countup2(g,x))%mod;
	}
	return dp1[root] = cnt;
}


int main() {


    int n, m; scanf("%d%d", &n, &m);
    int s, t; scanf("%d%d", &s, &t);
    start = s-1;
    goal = t-1;
    vector<tuple<int, int, ll> > edges(2*m);

    REP (i, m) {

        int a, b, c; scanf("%d%d%d", &a, &b, &c);

        -- a; -- b;

        edges[i] = make_tuple(a, b, c);
        edges[i+m] = make_tuple(b, a, c);
    }
    // solve
    vector<vector<pair<int, ll >> > g(n);
    vector<vector<pair<int, ll >> > rev_g(n);
    map<tuple<int, int, int>, int> count_edges;
    for (auto edge : edges) {
        int a, b, c; tie(a, b, c) = edge;
        g[a].emplace_back(b, c);
        rev_g[b].emplace_back(a, c);
        count_edges[edge] += 1;
    }
    auto dist = dijkstra(g, start);
    auto rev_dist = dijkstra(rev_g, goal);
    vector<vector<int> > h(n),h_rev(n);
    REP (i, n) {
        for (auto edge : g[i]) {
            int j, cost; tie(j, cost) = edge;
            if (dist[i] + cost + rev_dist[j] == dist[goal]) {
                h[i].push_back(j);
                h_rev[j].push_back(i);
            }
        }
    }
    ll ttt = dist[goal];
    vector<pair<int,int> > ppp;
    REP(i,n){
    	for(auto x : h[i]){
    		//cout << i << " " << x << endl;
    		if(dist[i]<(double)ttt/2.0&&rev_dist[x]<(double)ttt/2.0){
    			
    			ppp.push_back(make_pair(i,x));
    		}
    	}
    }
    set<int> st;
    if(ttt%2==0){
	    REP(i,n){
	    	if(dist[i]==ttt/2){
	    		st.insert(i);
	    	}
	    }
	}
    long long a = countup(h,start);
    long long b = countup2(h_rev,goal);
    dp1[start] = 1;
    dp2[goal] = 1;
    long long c = 0;
    for(auto x:ppp){
    	ll k =(dp1[x.first] * dp2[x.second])%mod;
    	c = (c+k*k) %mod;
    }
    for(auto x:st){
    	ll k = (dp1[x]*dp2[x])%mod;
    	c = (c+k*k)%mod;
    }
    cout << (a*b + mod - c)%mod << endl;
    return 0;
}