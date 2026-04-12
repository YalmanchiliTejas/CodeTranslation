// Author - Sumit 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx")
 
#define ll long long
#define int ll
#define ps push
#define pb emplace_back
#define INF 1LL<<60
#define MOD 1e9+7 
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int,int>>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define lower(v,x) (lower_bound(all(v),x)-v.begin())
#define upper(v,x) (upper_bound(all(v),x)-v.begin())
#define debug(x) cout << x << "\n";
#define debug2(x,y) cout << x << " " << y << "\n";
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T, typename U> inline void remin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void remax(T &x, U y) { if(x < y) x = y; }
template<typename T> T pow(T a,T b, T m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
inline string to_str(int a){ 
    char x[100]; 
    sprintf(x, "%lld", a); 
    string s = x;
    return s; 
}

inline int to_int(string a){
    char x[100];
    int res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

inline constexpr ll modulo(const ll n, const ll m = MOD) {
    ll k = n % m;
    return k + m * (k < 0);
}

inline ll inv(const ll n, const ll m = MOD) {
    ll a = n, b = m, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return modulo(x, m);
}

// Debug

#define Debug(...)                                                             \
    {                                                                          \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                     \
        for (auto &&X : {__VA_ARGS__}) cerr << "[" << X << "] ";               \
        cerr << endl;                                                          \
    }

#define vdump(a,x,y)                                                           \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(__i,x,y) if (__i) cerr << " " << a[__i];                           \
        else cerr << a[__i];                                                   \
        cerr << "]" << endl;                                                   \
    }

template<typename C, 
         typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
         typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr
         >
std::ostream &operator<<(std::ostream &os, const C &container){
  bool first = true;
  std::stringstream ss; 
  cerr << '[';
  for(const auto &x : container){
    if (!first){
      cerr << ", ";
    }
    first = false;
    cerr << x;
  }
  cerr << ']';
  cerr<<endl;       
  return os << ss.str();
}

void solve(){
    string s;
    cin>>s;
    if(s=="AAA"||s=="BBB"){
        debug("No");
    }else{
        debug("Yes");
    }
}

 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t=1;
    // cin>>t;
    WL(t){
        solve();
    }

    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
}