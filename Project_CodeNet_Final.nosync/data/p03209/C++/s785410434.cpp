#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e16;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

ll p2[60];
ll memo[60];

ll solve(ll n, ll x){
    if(n == 0){
        if(x >= 1) return 1;
        else return 0;
    }
    if(memo[n] != -LINF && x == 4*p2[n]-3){
        return memo[n];
    }
    if(x <= 0) return 0;
    else if (n >= 1){
        ll anm = 4*p2[n-1]-3;
        if(x <= anm)return solve(n-1, x-1);
        if(x == anm+1){
            return memo[n-1] = solve(n-1, anm);
        }
        else if(x == anm+2) return solve(n-1, anm) + 1;
        else{
            ll ans = p2[n]-1 + 1 + solve(n-1, x-(anm+2));
            return ans;
        }
    }
    return 0;
}

int main(){
    ll N, X; cin >> N >> X;
    
    ll tmp = 1;
    REP(i, 60){
        p2[i] = tmp; tmp *= 2;
        memo[i] = -LINF;
    }
    ll ans = solve(N, X);
    cout << ans << endl;
    return 0;
}
