#include<bits/stdc++.h>
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(vector<vector<T>> x){cerr<<"\n{"; int f=x.size();for(int i=0;i<f;i++){cerr<<"("; int g=x[i].size(); for(auto j:x[i]){cerr<<j; (--g!=0)?cerr<<",":cerr<<"";}cerr<<")\n";}cerr<<"}";}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void __print(vector<bool> x){cerr<<"{";int f=x.size();for(auto i:x){cerr<<i;(--f !=0)?cerr<<",":cerr<<"";}cerr<<"}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifndef ONLINE_JUDGE
#define trace(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define trace(x...)
#endif
 
template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}
 
template<typename... T>
void writ(T&&... args) {
    ((cout << args << " "), ...);
}
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
#define INF (ll)1e18
#define IINF (int)1e9
#define EPS 1e-9

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<ull> arr(n),suf(n);
    for(auto &i: arr) cin>>i;
    //First calc the suffix sum
    suf=arr;
    for(int i=n-2;i>=0;i--){
        suf[i]=(suf[i]+suf[i+1])%MOD;
    }
    //trace(suf);
    ull x=0;
    for(int i=n-2;i>=0;i--){
        ll temp = (arr[i]*suf[i+1])%MOD;
        x = (x + temp)% MOD;
    }
    cout<<x%MOD;
    return 0;
}

