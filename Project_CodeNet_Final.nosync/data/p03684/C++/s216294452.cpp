    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N=1e5+5;
    vector<pair<pair<ll,ll>,ll> >v;
    vector<pair<ll,ll> >g[N];
    bool vstd[N];
    ll ans;
    int main(){
    	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    	int n;cin>>n;
    	for(int i=1;i<=n;i++){
    		ll a,b;cin>>a>>b;
    		v.push_back({{a,b},i});
    	}
    	sort(v.begin(),v.end());
    	for(int i=0;i<n-1;i++){
    		g[v[i].second].push_back({v[i+1].second,v[i+1].first.first-v[i].first.first});
    		g[v[i+1].second].push_back({v[i].second,v[i+1].first.first-v[i].first.first});
    	}
    	for(int i=0;i<v.size();i++){
    		swap(v[i].first.first,v[i].first.second);
    	}
    	sort(v.begin(),v.end());
    	for(int i=0;i<n-1;i++){
    		g[v[i].second].push_back({v[i+1].second,v[i+1].first.first-v[i].first.first});
    		g[v[i+1].second].push_back({v[i].second,v[i+1].first.first-v[i].first.first});
    	}
    	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
    	pq.push(make_pair(0,1));
    	while(pq.size()){
    		int node=pq.top().second;ll cost=pq.top().first;
    		pq.pop();
    		if(vstd[node])continue;
    		vstd[node]=true;
    		ans+=cost;
    		for(auto u:g[node]){
    			pq.push({u.second,u.first});
    		}
    	}
    	cout<<ans;
    	return 0;
    }