
/*
shakespere said: 

I always feel happy, you know why? Because I don’t expect anything from anyone; expectations always hurt. Life is short. So love your life. Be happy. And keep smiling.

Just live for yourself and always remember:

Before you speak… Listen
Before you write… Think
Before you spend… Earn
Before you pray… Forgive
Before you hurt… Feel
Before you hate… Love
Before you quit… Try
Before you die… Live
/**********************************************
#code by --> @ { shadat </> sk40 [ o_o  ^_^ ] } }
-----------------------------------------------
# The Quick Brown Fox Jumps over the Lazy Dog. 
**********************************************/
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 1 * 1e5 + 10;
 
ll res;
std::vector<ll> v[N];
std::map<ll, ll> mp;
std::vector<pair<ll, ll>> vv;
std::vector<ll> x, xx;
bool isprime(ll n){
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
} 

int mss() {    
        	ll n;
    	cin >> n;
    	vv.push_back({0, 0});
    	for (int i = 1; i <= n; ++i){
    		ll len;
    		ll mx = 0, mn = inf;
    		cin >> len;
    		for (int j = 0; j < len; ++j){
    			cin >> res;
    			mx = max(res, mx);
    			mn = min(res, mn);
    			v[i].push_back(res);
    		}
    		vv.push_back({mn, mx});
    	}
    	for (int i = 1; i <= n; ++i){
    		std::map<ll, ll> mpp;
    		mpp[0]++;
    		for(auto j : v[i]){
    			mpp[j]++;
    		}
    		bool flag = 0;
    		for(auto j : v[i]){
    			mpp[j]--;
    			if(!mpp[j])mpp.erase(j);
    			auto itr = mpp.rbegin();
    			if(itr->first > j) {flag = 1; break;}
    		}
    		if(!flag){mp[i]++;}
    		mpp.clear();
    	}
    	ll ans = (n - mp.size()) * n + mp.size() * (n - mp.size());
     
    	for(auto i : mp){
    		x.push_back(vv[i.first].first);
    		xx.push_back(vv[i.first].second);
    	}
    	sort(x.begin(), x.end());
    	sort(xx.begin(), xx.end());
     
    	for (int i = 0; i < x.size(); ++i){
    		auto idx = upper_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
    		ans += xx.size() - idx;
    	}
    	cout << ans;

	return 0;
}
struct record{
	short bit;
	short up;
	short down;
	short vrtx;
}; 
int main(){
   int a,b;
   cin>>a>>b;
   if(a==b && a!=0){
       cout<<"Yes\n";
   }
   else{
       cout<<"No\n";
   }
    
	return 0;
}