#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define veci vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))


using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
//template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
//template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}
template<typename T>
/*istream& operator >> (istream& is, vector<T>& vec){
    for(T& x:vec) is >> x;
    return is;
}*/
const ll INF=1e9+7;

vector<ll> len;

ll dfs(ll N,ll X){
    if(N==0 && X==1) return 1;
    if(X==1) return 0;
    if(2<=X && X<=len[N-1]+1) return dfs(N-1,X-1);
    if(X==len[N-1]+2) return dfs(N-1,len[N-1])+1;
    if(len[N-1]+3<=X && X<=2*len[N-1]+2) return dfs(N-1,len[N-1])+dfs(N-1,X-len[N-1]-2)+1;
    if(X==2*len[N-1]+3) return 2*dfs(N-1,len[N-1])+1;
}

int main()
{
    ll n,x;
    cin >> n >> x;
    len.resize(n+1);
    len[0]=1;
    for(ll i=1;i<=n;i++){
        len[i]=2*len[i-1]+3;
    }
    cout << dfs(n,x) << endl;
    return 0;
} 
