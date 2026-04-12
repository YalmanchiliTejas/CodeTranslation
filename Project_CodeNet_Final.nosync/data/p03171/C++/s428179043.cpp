  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define ll long long
  #define int long long
 
  const int N=1e9+7;

  
  int32_t main()
  { 
   /* #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
   
    IOS
  int n;
  cin >> n;
  vector<int> x(n);
  long long sum = 0;
  for (int&v : x) {
    cin >> v;
    sum += v;
  }

  vector<vector<long long>> dp(n,vector<long long>(n));
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
  dp[l][r] = x[l];
      } else {
  dp[l][r] = max(x[l]-dp[l+1][r],
           x[r]-dp[l][r-1]);
      }
    }
  }
  cout <<dp[0][n-1] << endl;

  return 0;
}