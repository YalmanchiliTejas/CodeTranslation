#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define repi(i,a,b) for(int i=a; i<=(b); ++i)
#define rrep(i,n) for(int i=(n-1); i>=0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define to_s to_string
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define pr(x) cout<<(x)<<'\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
#define yes "Yes"
#define no "No"
using namespace std;
using ll = long long;
using Edge = pair<int,long long>;
using Graph = vector<vector<Edge>>;
typedef pair<int,int> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
int MOD = 1e9 + 7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll devc(ll x, ll y){return 1 + (x-1)/y;}

ll LIS(vector<ll>& sequence){
    multiset<ll> s;
    s.insert(sequence[0]);
    
    for(ll i = 1; i < sequence.size(); i++){
        ll now = sequence[i];
        //広義単調増加列の場合、以下を now >= *--s.end()にする
        if(now >= *--s.end()) s.insert(now);
        else{
            auto itr = s.upper_bound(now);
            s.erase(itr);
            s.insert(now);
        }
    }
    return s.size();
}

int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    ll tp;
    rep(i,N) cin >> tp, A[i] = -tp;
    pr(LIS(A));
    return 0;
}