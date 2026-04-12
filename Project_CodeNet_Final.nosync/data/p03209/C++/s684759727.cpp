#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
#include <cstdint>
#include <chrono>

using namespace std;
#define     loop(n,i,a)     for(ll i=a;i<n;i++)
#define     loopR(n,i,a)    for(ll i=a-1;i>=n;i--)
#define     all(arr,n)      arr,arr+n
#define     allv(v)         (v).begin(),(v).end()
#define     rallv(v)        (v).rbegin(),(v).rend()
#define     m_p             make_pair
#define     ll              long long
#define     pii             pair<ll,ll>
#define     vi              vector<int>
#define     vll             vector<ll>
#define     vii             vector<pii>
#define     sz(x)           (int)x.size()
#define     pb              push_back
#define     endl            "\n"
#define     Endl            "\n"
#define     f               first
#define     s               second
#define     mem(dp,n)       memset(dp,n,sizeof dp)
template<typename T>void max_self(T &a,T b){a=max(a,b);}
template<typename T>void min_self(T &a,T b){a=min(a,b);}
int dx[] = { 1 , 0 ,-1 , 0 ,-1 ,-1 , 1 , 1 };
int dy[] = { 0 , 1 , 0 ,-1 ,-1 , 1 ,-1 , 1 };
int KnightI[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int KnightJ[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void fast(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
        vector<string> __attribute__ ((unused)) args,
        __attribute__ ((unused)) int idx,
        __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
const ll mxN=4e5+10,oo=0x3f3f3f3f,MOD=1e9+7;
const long double PI = acos(-1),eps=1.0e-14;
ll go(ll n,ll x){
    ll len=(1ll<<(n+1))-3;
    ll p=(1ll<<n)-1;
    if(n==0)return 1;
    if(x==1)return 0;
    else if(x<=len+1)return go(n-1,x-1);
    else if(x==len+2)return p+1;
    else if(x<=(len*2)+2)return p+1+go(n-1,x-len-2);
    else return p*2+1;
}
void solve(){
    ll n,x;
    cin>>n>>x;
    cout<<go(n,x)<<endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast();
    solve();

}
