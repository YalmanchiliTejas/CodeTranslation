#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i=0;i<t;i++)
#define ll long long int
#define ld long double
#define umpl unordered_map<ll,ll> 
#define vl vector<ll>
#define vld vector<ld>
#define vvl vector<vl>
#define pb push_back
#define pll pair<ll,ll>
#define inf 1e18
#define pcout(x,p) cout<<fixed<<setprecision(p)<<x
#define all(a) a.begin(),a.end()
#define endl "\n"
ll mod;
inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}
inline ll ceil(ll a,ll b){return (a%b==0)?(a/b):(a/b+1);}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    for(auto v : V) os << v <<"  ";
    return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
struct comp { 
    template<class T1,class T2,class T3,class T4>
    bool operator()(const pair<T1,T2> &p1,const pair<T3,T4> &p2){
        return p1.first<p2.first;
    }
};


int main(){
	fio;	
	ll n;cin>>n;
	ll a1;cin>>a1;
	cin>>mod;
	ll ans=a1;
	map<ll,ll> mp,pre,revmp;
	mp[1]=a1;pre[1]=a1;revmp[a1]=1;
	for(ll i=2;i<=n;i++){
		ll prev=a1;		
		a1=mul(a1,a1);
		if(revmp.find(a1)!=revmp.end()){
			ll pos=revmp[a1];
			ll size=i-pos;
			ll rem=n-i+1;
			ll temp=pre[i-1]-pre[pos-1];
			ans+=(rem/size)*temp;
			ll curr;
			if(rem%size==0){
				curr=0;
				break;
			}else{
				for(ll j=0;j<rem%size;j++){
					prev=mul(prev,prev);
					ans+=prev;
				}
				break;
			}
		}else{
			ans+=a1;
			pre[i]=pre[i-1]+a1;
			revmp[a1]=i;
		}
	}
	cout<<ans<<endl;
}