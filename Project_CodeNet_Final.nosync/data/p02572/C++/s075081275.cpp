  #include <bits/stdc++.h>
  using namespace std;

  #define ll long long
  #define int long long
  #define f(i,l,n) for(ll i=l;i<n;i++)
  #define E "\n"
  #define bp __builtin_popcount
  const int M = 1e9+7;

  
  int32_t main()
  {

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

   
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    int sum=0;
    f(i,0,n) cin >> a[i],sum=(sum+a[i])%M;

    int ans=0;

    f(i,0,n-1)
    {
      sum=(sum-a[i]+M)%M;
      ans=(ans+(a[i]*sum)%M)%M;
    }
    cout<<ans;

    return 0;
  }