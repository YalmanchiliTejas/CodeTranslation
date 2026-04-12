    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N=1e5+5;
    vector<pair<pair<ll,ll>,ll> >v;
    vector<pair<ll,pair<int,int> > >edg;
    ll ans;
    int sz[N],arr[N];
    void init(){
    	for(int i=0;i<N;i++){
    		sz[i]=1;
    		arr[i]=i;
    	}
    	return ;
    }
    int root(int a){
    	if(arr[a]!=a){
    		return arr[a]=root(arr[a]);
    	}else{
    		return a;
    	}
    }
    void un(int a,int b,ll cost){
    	int root_a=root(a),root_b=root(b);
    	if(root_a==root_b){
    		return ;
    	}else{
    		ans+=cost;
    		if(sz[root_a]>=sz[root_b]){
    			sz[root_a]+=sz[root_b];
    			arr[root_b]=root_a;
    		}else{
    			sz[root_b]+=sz[root_a];
    			arr[root_a]=root_b;
    		}
    	}
    	return;
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    	init();
    	int n;cin>>n;
    	for(int i=1;i<=n;i++){
    		ll a,b;cin>>a>>b;
    		v.push_back({{a,b},i});
    	}
    	sort(v.begin(),v.end());
    	for(int i=0;i<n-1;i++){
    		edg.push_back({v[i+1].first.first-v[i].first.first,{v[i].second,v[i+1].second}});
    		edg.push_back({v[i+1].first.first-v[i].first.first,{v[i+1].second,v[i].second}});
    	}
    	for(int i=0;i<v.size();i++){
    		swap(v[i].first.first,v[i].first.second);
    	}
    	sort(v.begin(),v.end());
    	for(int i=0;i<n-1;i++){
    		edg.push_back({v[i+1].first.first-v[i].first.first,{v[i].second,v[i+1].second}});
    		edg.push_back({v[i+1].first.first-v[i].first.first,{v[i+1].second,v[i].second}});
    	}
    	sort(edg.begin(),edg.end());
    	for(auto u:edg){
    		un(u.second.first,u.second.second,u.first);
    	}
    	cout<<ans;
    	return 0;
    }