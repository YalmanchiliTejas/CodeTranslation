
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>
#include <array>

using namespace std;

template<typename M, typename N>
istream& operator>>(istream&is, pair<M,N> & p){is >> p.first >> p.second; return is;}
template<typename M>
istream& operator>>(istream&is, vector<M> & v){for(auto &it:v) is >> it; return is; }
template<typename M>
istream& operator>>(istream&is, vector<vector<M>> & v){for(auto &it:v) is >> it; return is; }
template<typename M, typename N>
ostream& operator<<(ostream&os, const pair<M,N> &p){os << p.fi << ' ' << p.se << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<M> &v){for(auto it: v)os << it << ' ';cout << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<vector<M>> &v){for(auto it: v)os << it;return os;}

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mn(x) *min_element((x).begin(),(x).end())
#define mx(x) *max_element((x).begin(),(x).end())
#define acc(x) accumulate((x).begin(),(x).end(),0ll)
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef  unsigned long long  ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

const ld pi=acos(-1);
const ll inf=(ll)1e9+10;
//const int mod=1000000007;
const int mod=998244353;

int n,m,k;
const int N=3e5+10;




int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, m, x;
    cin >> n >> x >> m;
    if(n<2*m){
        ll st=x;
        n--;
        while(n--){
            st+=(x*x%m);
            (x*=x)%=m;
        }
        cout << st << el;
        return 0;
    }
    vb vis(m);
    vis[x]=true;
    ll last=x;
    vll tt;
    tt.pb(0);
    tt.pb(x);
    while(!vis[last*last%m]){
        (last*=last)%=m;
        tt.pb(last);
        vis[last]=true;
    }
    (last*=last)%=m;
    ll ans=0;
    for(int i=1; i<tt.size(); i++, n--){
        if(tt[i]==last){
            if(i==1)break;
            tt.erase(tt.begin()+1,tt.begin()+i);
            break;
        }
        ans+=tt[i];
    }
    for(int i=1; i<tt.size(); i++){
        tt[i]+=tt[i-1];
    }
    cout << ans+n/(tt.size()-1)*tt.back()+tt[n%(tt.size()-1)] << el;
    
    return 0;
}






