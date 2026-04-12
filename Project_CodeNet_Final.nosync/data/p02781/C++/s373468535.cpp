#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
#include <functional>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef long double LD;
typedef vector<LD> vld;
typedef vector<pair<LD, LD>> vpld;
typedef pair<ll, ll> PL;
typedef vector<PL> vpl;
typedef vector<vector<PL>> vvpl;
typedef vector<vvpl> vvvpl;
typedef pair<ll, PL> TL;
typedef vector<TL> vtl;
typedef vector<vtl> vvtl;
typedef long double ld;
typedef vector<ld> vld;
const ll LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define epb emplace_back
#define ALL(X) (X).begin(),(X).end()

template <typename T> T gcd(T a, T b) {return (a == 0) ? b : gcd(b%a, a);}
template <typename T> T lcm(T a, T b) { return a / gcd(a, b) * b;}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec /* copy */){
    sort(ALL(vec)); vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec;
}

inline ll popcnt(ll x){return __builtin_popcountll((unsigned long long)x);};
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
//friend bool operator<(const tpl& lhs, const tpl& rhs){
//    return std::tie(lhs.l, lhs.r) < std::tie(rhs.l, rhs.r);
//}

bool bit(ll st, ll b){return ((st>>b)&1) == 1;}


int main(){
#ifdef __DEBUG_LOCAL__
    ifstream file("../../../../../in.txt"); if(file.is_open()) cin.rdbuf(file.rdbuf());
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string N; cin >> N;
    ll K; cin >> K;
    vvvl dp(N.size()+1, vvl(2, vl(K+1, 0)));
    dp[0][0][0] = 1;
    rep(i, N.size()){
        ll d = N[i]-'0';
        if(i == 0){
            if(N[i] == '1'){
                rep(k, K+1){
                    dp[i+1][0][k+1] += dp[i][0][k];
                    dp[i+1][1][k] += d*dp[i][0][k];
                }
                continue;
            }
        }
        rep(k, K+1){
            if(N[i] == '0'){
                dp[i+1][0][k] += dp[i][0][k];
                dp[i+1][1][k] += dp[i][1][k]; // 0
                if(k+1 <= K) dp[i+1][1][k+1] += 9*dp[i][1][k]; // other than 0
            }
            else{
                if(k+1 <= K) dp[i+1][0][k+1] += dp[i][0][k];
                if(k+1 <= K) dp[i+1][1][k+1] += (d-1) * dp[i][0][k]; // p -> p-1 (p >= 2)
                dp[i+1][1][k] += dp[i][0][k]; // 1 -> 0
                
                dp[i+1][1][k] += dp[i][1][k]; // 0
                if(k+1 <= K) dp[i+1][1][k+1] += 9*dp[i][1][k]; // other than 0
            }
        }
    }
    cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endstr;
    return 0;
}
