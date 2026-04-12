  #pragma GCC optimize("Ofast")
  #pragma GCC target("avx,avx2,fma")
  #include <bits/stdc++.h>
  using namespace std;
  //---------------------------------//
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
  #define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
  #else
  #define deb(x...)
  #endif
 //------------------------------//

  typedef long long int ll;
  typedef pair<int,int> pi;
  typedef pair<ll,ll> pll;
  typedef vector<int> vi;
  typedef vector<ll> vll;
  typedef vector<pi> vpi;
  typedef vector<pll> vpll;

  #define  ff           first
  #define  ss           second
  #define  pb           push_back
  #define  IOS          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define  all(x)       (x).begin(), (x).end()
  #define  ps(x,y)      fixed<<setprecision(y)<<x
  #define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)

  const ll MOD = 1e9 + 7;
  const ll INF = 1e18;
  const ll maxn = 1e6 + 4;

  int n;
  string s;
  string ans;
  bool check(){
    bool ok = true;
    for(int i=0;i<n;i++){
      if(ans[(i+1)%n]=='0'){
         if(ans[i]=='f'){
            if(s[i]=='o'){
              ans[(i+1)%n] = (ans[(n+i-1)%n]=='g'?'f':'g');
            }
            else{
              ans[(i+1)%n] = (ans[(n+i-1)%n]=='g'?'g':'f');
            }
         }
         else{
           if(s[i]=='x'){
              ans[(i+1)%n] = (ans[(n+i-1)%n]=='g'?'f':'g');
            }
            else{
              ans[(i+1)%n] = (ans[(n+i-1)%n]=='g'?'g':'f');
            }
         }
      }
    }
    for(int i=0;i<n;i++){
      if(ans[i]=='f'){
          if(s[i]=='x'){
            ok &= (ans[(n+i-1)%n]==ans[(i+1)%n]);
          }
          else{
            ok &=(ans[(n+i-1)%n]!=ans[(i+1)%n]);
          }
        }
        else{
          if(s[i]=='o'){
            ok &= (ans[(n+i-1)%n]==ans[(i+1)%n]);
          }
          else{
            ok &=(ans[(n+i-1)%n]!=ans[(i+1)%n]);
          }          
        }  
    }
    return ok;
  }  
  void print(string ans){
    for(char x:ans){
      cout << (x=='f'?'W':'S');
    }
  }
  void solve(){
    cin >> n;
    cin >> s;
    // first is fox
    ans=string(n,'0');
    ans[0] = 'f';
      if(s[0]=='o'){
        ans[1]='f';
        ans[n-1]='g';
        if(check()){
          print(ans);
          return;
        }
        ans=string(n,'0');
        ans[0]='f';
        ans[1]='g';
        ans[n-1]='f';
        if(check()){
          print(ans);
          return;
        }
      }
      else{
      ans = string(n,'0');
      ans[0]='f';
        ans[1]='f';
        ans[n-1]='f';
        if(check()){
          print(ans);
          return;
        }
        ans=string(n,'0');
        ans[0]='f';
        ans[1]='g';
        ans[n-1]='g';
        if(check()){
          print(ans);
          return;
        }        
      }
    ans = string(n,'0');
    ans[0]='g';
      if(s[0]=='o'){
        ans[1]='g';
        ans[n-1]='g';
        if(check()){
          print(ans);
          return;
        }
        ans=string(n,'0');
        ans[0]='g';
        ans[1]='f';
        ans[n-1]='f';
        if(check()){
          print(ans);
          return;
        }
      }
      else{
      ans = string(n,'0');
      ans[0]='g';
        ans[1]='f';
        ans[n-1]='g';
        if(check()){
          print(ans);
          return;
        }
        ans=string(n,'0');
        ans[0]='g';
        ans[1]='g';
        ans[n-1]='f';
        if(check()){
          print(ans);
          return;
        }        
      }
      cout << -1;
  }

  int main(){
    IOS
    	solve();
    //cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }

// integer overflow
