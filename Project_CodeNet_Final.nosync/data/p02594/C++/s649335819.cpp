#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define debug(x...) cout << #x << " = "; _print(x)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vll;
#define rep(i,a,b) for (ll i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define mp make_pair 
#define pb push_back
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL) 
const int mod = 1e9 + 7, mxn = 1e5 + 1;

int solve(){
    int x;
    cin>> x;
    if(x >= 30)
        cout<< "Yes\n";
    else
        cout<< "No\n";
    return 0;
}
//Counting problems: Sometimes easier to find complement of the answer
 
int main()
{
    fast;
    int t = 1;
    //cin>> t;
    while(t--){  
        solve();
    }
    return 0;
}
//v.clear(), vis.clear(); vis.resize(n + 1, 0), v.resize(n + 1);
 
/*  inv[1] = 1; // inv is ll
    for(int i=2; i<=mxn; ++i)
        inv[i]=mod-mod/i*inv[mod%i]%mod;*/
        
// lower bound   >=  
// upper bound   >
// vector<int>().swap(vec); //free memory from vec
