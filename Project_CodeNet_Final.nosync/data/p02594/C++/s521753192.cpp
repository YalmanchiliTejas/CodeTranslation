/*input
3
xyx


*/
 
 
 
#include <bits/stdc++.h>
using namespace std;
 
 
 
#define int long long int
#define rep(i,n) \
    for(int i = 0; i < n; i++)
#define rep2(i, a, b) \
    for(int i = a; i < b; i++)
#define all(c) \
    c.begin(), c.end()
#define init(arr, num) \
    memset(arr, num, sizeof(arr))
#define fast\
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inputFile \
    freopen("input.txt", "r", stdin); 
#define outputFile \
    freopen("output.txt", "w", stdout);
#define modM 1000000007
#define PI 3.1415926535897932
#define F first
#define S second  
#define pb push_back  
#define INF 3e18
#ifdef gaviria
#define TRACE
#endif
#ifdef TRACE
#define trace(...) _f(#VA_ARGS, __VA_ARGS_)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
 
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
 
 
typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair< ll, ll > ii;
typedef unordered_set<int> usi;
 
 
 
ll n,i,j,k,m,c;

void solve()
{
cin>>n;

if(n>=30)
{
    cout<<"Yes";
}
else cout<<"No";
}
 
 
 
 
 
signed main()
{// inputFile;


    fast;
    int T = 1;
    // cin >> T;
    ll h=T;
    while(T--){
 
        solve();
        cout<<endl;
 
     
        
        
 
    }
    
    
    return 0;
 
}