    /*
    Life Before Death, Strength Before Weakness, Journey Before Destination
    ------------------------------------------------------------------------
    You don't become great by trying to be great.
    You become great by wanting to do something,
    and then doing it so hard that you become great in the process.
    */

    //#pragma comment(linker, "/stack:200000000")
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    #include <bits/stdc++.h>
    using namespace std;
    
    #define TRACE
    
    #ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
    #else
    #define trace(...)
    #endif
    
    #define rep(i, n)    for(int i = 0; i < (n); ++i)
    #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
    #define repD(i, a, n)  for(int i = a; i >= (n); --i)
    #define trav(a, x) for(auto& a : x)
    #define all(x) x.begin(), x.end()
    #define sz(x) (int)(x).size()
    #define fill(a)  memset(a, 0, sizeof (a))
    #define fst first
    #define snd second
    //#define mp make_pair
    #define pb push_back
    #define PI           3.141592653589793238462643383279502884197169399  /* pi */
    #define te  ll ti;   cin >> ti;  while(ti--) solve();  
    typedef long double ld;
    typedef long long ll;
    typedef pair<ll, ll> pii;
    typedef vector<ll> vi;
    const int maxN = 1030000;

    void solve() {
      ll n, k;
      cin >> n >> k;
      ll sum = 0;
      repA(i, k+1, n){
      //cout << (i-k)*(n/i) << " " << max(0ll, n%i - k + 1) << endl;
        sum+= max(0ll, i-k)*(n/i);
        sum+=max(0ll, n%i - k + 1);
        !k ? --sum:0;
      }
      cout << sum << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //te
      solve();
      return 0;
    } 