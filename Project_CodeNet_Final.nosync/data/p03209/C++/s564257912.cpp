#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
#define P(a,b) make_pair(a,b);
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

ll N,X;
map<pair<ll,ll>,ll> mp;

ll F(ll k,ll x){
    if(mp.count(make_pair(k,x)) != 0) return mp[make_pair(k,x)];
    ll n = 4 * (ll)pow(2,k) - 3,m = 2 * (ll)pow(2,k) - 1;
    if(x == 0)return 0;
    if(k == 0)return 1;
    if(x == 1)return 0;
    if(x > n) return 0;
    if(x < m){
        return mp[make_pair(k,x)] = F(k-1,x-1);
    }else{
        return mp[make_pair(k,x)] = (F(k-1,m-2) + 1 + F(k-1,min(x-m,4 * (ll)pow(2,k-1) - 3)));
    }
}

int main(){
    cin >> N >> X;
    cout << F(N,X) << endl;
}
