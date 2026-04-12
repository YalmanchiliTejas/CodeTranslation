  #include <bits/stdc++.h>
  #include <chrono>

  using namespace std;
  using namespace std::chrono; 

  typedef long long int ll;

  #define MOD (ll)(1e9+7)
  #define endl "\n"
  #define pb push_back
  #define TEST_CASES  ll t;cin>>t;while(t--)
  #define forn(i,a,n) for (int i = a; i < n; ++i)
  #define f first
  #define s second
  #define all(x) x.begin(), x.end()

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
  void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
  void _print() {cerr << "]\n";}
  template <typename T, typename... V>
  void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
  #ifndef ONLINE_JUDGE
  #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
  #else
  #define debug(x...)
  #endif
  
  ll powD(ll x,ll y){
    ll res = 1;
    while(y > 0){
      if(y & 1)
        res = (res*x)%MOD;
      x = (x*x)%MOD;
      y = y>>1;
    }
    return res;
  }


  /*CHECK FOR CORNER CASES FOR GOD'S SAKE*/
  int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    if(x>=30)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
   
  
