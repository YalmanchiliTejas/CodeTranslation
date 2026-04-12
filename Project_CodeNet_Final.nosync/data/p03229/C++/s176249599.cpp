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


int main(){
    ll N; cin >> N;
    multiset<ll> a; REP(i, N){ ll x; cin >> x; a.insert(x);};
    multiset<ll> b = a;
    ll ans = 0;
    ll l = *a.begin(), r = *a.begin();
    a.erase(a.begin());
    while(a.size() > 0){
        auto beg = a.begin();
        auto rbeg = a.rbegin();
        ll bd = max(abs(*beg - l), abs(*beg - r));
        ll rd = max(abs(*rbeg - l), abs(*rbeg -r));
        if(bd > rd){
            ans += bd;
            if(abs(*beg - l) > abs(*beg - r)) l = *beg;
            else r = *beg;
            a.erase(beg);
        }
        else{
            ans += rd;
            if(abs(*rbeg - l) > abs(*rbeg - r)) l = *rbeg;
            else r = *rbeg;
            a.erase((++rbeg).base());
        }
    }
    
    ll ans2 = 0;
    l = *b.rbegin(); r = *b.rbegin();
    b.erase((++b.rbegin()).base());
    while(b.size() > 0){
        auto beg = b.begin();
        auto rbeg = b.rbegin();
        ll bd = max(abs(*beg - l), abs(*beg - r));
        ll rd = max(abs(*rbeg - l), abs(*rbeg -r));
        if(bd > rd){
            ans2 += bd;
            if(abs(*beg - l) > abs(*beg - r)) l = *beg;
            else r = *beg;
            b.erase(beg);
        }
        else{
            ans2 += rd;
            if(abs(*rbeg - l) > abs(*rbeg - r)) l = *rbeg;
            else r = *rbeg;
            b.erase((++rbeg).base());
        }
    }
    cout << max(ans, ans2) << endl;
    return 0;
}
