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
using namespace std;
#define     loop(n,i,a)     for(int i=a;i<n;i++)
#define     loopR(n,i,a)    for(int i=n-1;i>=a;i--)
#define     all(arr,n)      arr,arr+n
#define     allv(v)         (v).begin(),(v).end()
#define     rallv(v)        (v).rbegin(),(v).rend()
#define     m_p             make_pair
#define     ll              long long
#define     pii             pair<ll,ll>
#define     vi              vector<int>
#define     vll             vector<ll>
#define     vii             vector<pair<ll,ll>>
#define     sz(x)           (int)x.size()
#define     pb              push_back
#define     endl            "\n"
#define     Endl            "\n"
#define     f               first
#define     s               second
#define     mem(dp,n)       memset(dp,n,sizeof dp)
#define     test(i)        cout<<i<<endl
int dx[] = { 1 , 0 ,-1 , 0 ,-1 ,-1 , 1 , 1 };
int dy[] = { 0 , 1 , 0 ,-1 ,-1 , 1 ,-1 , 1 };
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
const ll mxN=2e2+10,oo=0x3f3f3f3f,MOD=998244353;
const double PI = 3.14159265358979323846;

void solve(){
    int x;
    cin>>x;
    if(x>=30){
        cout<<"Yes"<<Endl;
    }
    else
        cout<<"No"<<endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast();
    solve();
}