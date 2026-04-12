  #include<bits/stdc++.h>

  #define int         long long
  #define pb          push_back
  #define pf          emplace_front
  #define all(a)      (a).begin(),(a).end()
  #define rall(a)     (a).rbegin(),(a).rend()
  #define pii 		pair<int,int>
  #define psi 		pair<string,int>
  #define vi 			vector<int>
  #define vpii  		vector<pii>
  #define vvi 		vector<vi>
  #define sz(x)	    (int)(x).size()
  #define x           first
  #define y           second
  #define endl        '\n'
  #define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #define MOD         1000000007
  #define hell        998244353
  #define prec(n) 	fixed<<setprecision(n)
  #define ini(a, i) 	memset(a, i, sizeof(a))
  #define output(x)   cout << (x ? "YES" : "NO")<<endl;
  using namespace std;

  #define debug(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<i<<" "; cout<< "]" << endl
  #define debugp(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<"("<<i.x<<","<<i.y<<")"<<" "; cout<< "]" << endl
  #define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout << endl; }
  void err(istream_iterator<string> it) {}
  template<typename T, typename... Args>
  void err(istream_iterator<string> it, T a, Args... args) {
      cout << "[" << *it << ": " << a << "]\t";
      err(++it, args...);
  }

  // const int dx[4] = { -1, 1, 0, 0};
  // const int dy[4] = {0, 0, -1, 1};
  // int dX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  // int dY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


  // Code from Here -------------------------------------------------------------------------------

  signed main() {
      tezz

      // #ifndef ONLINE_JUDGE
      // 	freopen("input.txt", "r", stdin);
      // 	freopen("output.txt", "w", stdout);
      // #endif

      int n;
      cin >> n;
      int a[n];
      int sum = 1;
      for(int i=0; i<n; i++){
          cin >> a[i];		
      }
      int pre[n+1];
      pre[n-1] = a[n-1];
      int ans = 0;
      pre[n]=0;
      for(int i=n-1; i>=0; i--){
          pre[i] = (pre[i+1] + a[i])%MOD;
      }
      for(int i=0; i<n; i++){
          ans = (ans + (pre[i+1] * a[i])%MOD)%MOD;
      }
      cout << ans << endl;

      return 0;
  }