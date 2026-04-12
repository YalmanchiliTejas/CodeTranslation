    #include<bits/stdc++.h>
    using namespace std;
     
    #define       pb(a)             push_back((a))
    #define       mp(a,b)           make_pair((a),(b))
    #define       REP(a,b)          for(ll i=(a);i<(b);i++)
    #define       REP2(a,b)         for(ll j=(a);j<(b);j++)
    #define       REPE(a,b,c,d)     REP(a,b)for(ll j=(c);j<(d);j++)
    #define       REPV(a,b,c)       for(ll (a)=b;(a)<(c);(a)++)
    #define       IREP(a,b)         for(ll i=(a);i>=(b);i--)
    #define       IREP2(a,b)        for(ll j=(a);j>=(b);j--)
    #define       IREPV(a,b,c)      for(ll (a)=b;(a)>=(c);(a)--)
    #define       all(v)            (v).begin(),(v).end()
    #define       Trvs(c)           for (auto it = (c).begin(); it != (c).end(); it++)
    #define       INF               INT_MAX
    #define       sz(x)             x.size()
    #define       flash             ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define       F                 first
    #define       S                 second
    #define       MOD               1000000007
     
    using         ll     = long long;
    using         vi     = vector<int>;
    using         vvi    = vector<vi>;
    using         vll    = vector<ll>;
    using         vvll   = vector<vll>;
    using         vb     = vector<bool>;
    using         vd     = vector<double>;
    using         vs     = vector<string>;
    using         pii    = pair<int, int>;
    using         pll    = pair<ll, ll>;
    using         pdd    = pair<double, double>;
    using         vpii   = vector<pii>;
    using         vvpii  = vector<vpii>;
    using         vpll   = vector<pll>;
    using         vvpll  = vector<vpll>;
    using         vpdd   = vector<pdd>;
    using         vvpdd  = vector<vpdd>;
     
     
    ll gcd(ll a,ll b){
    	if(b==0)return a;
    	return gcd(b,a%b);
    }
    ll lcm(ll a,ll b){
     
    	return a*b/gcd(a,b);
    }
     
    ll ceeel(ll n,ll a){
    	if(n%a==0) return n/a;
    	return n/a +1;
    }
    ll power(ll x, ll y){
    	ll ans=1;
    	REP(0,y){
    		ans*=x;
    	}
    	return ans;
    }
     
    void solve(){
    	ll n,m; cin >> n >> m;
    	if(n==m){
    		cout<<"Yes";
    	}
    	else cout<<"No";
    }
     
     
    	
     
     
    int main(){
     
    	flash
    
    	
    	//ll t;cin>>t;while(t--)
    	solve();
     
     
    	return 0;
    }