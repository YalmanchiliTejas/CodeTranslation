      #include<bits/stdc++.h>
      #include <ext/pb_ds/assoc_container.hpp>
      #include <ext/pb_ds/tree_policy.hpp>
      using namespace __gnu_pbds;
      using namespace std;
      #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
      #define ll            long long
      #define pb            push_back
      #define ppb           pop_back
      #define si            set <ll>
      #define endl          '\n'
      #define fr            first
      #define sc            second
      #define mii           map<ll,ll>
      #define msi           map<string,ll>
      #define mis           map<ll,string>
      #define rep(i,a,b)    for(ll  i=a;i<b;i++)
      #define all(v)        v.begin(),v.end()
      #define pii           pair<ll,ll>
      #define vi            vector<ll>
      #define vii           vector<pair<ll,ll>>
      #define vs            vector<string>
      #define sz(x)         (ll)x.size()
      #define rt            return
      #define spl           " "
      #define M             1000000007
      #define bs            binary_search
      #define rev(a)        reverse(all(a));
      #define sp(n)         setprecision(n)
      #define spl           " "
      #define arr(a,n)      rep(i,0,n) cin>>a[i]
      #define mod           998244353
      #define time          cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
      #define INF           1ll<<31
      #define rt            return
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
      ll bpow(ll a, ll b, ll mm = M)
      {
          ll res = 1;

          while(b)
          {
              if(b & 1)
                  res = (res * a) % mm;
              a = (a * a) % mm;

              b >>= 1;
          }

          return res;
      }
      ll modInverse(ll A,ll mm)
      {
          return bpow(A,mm-2,mm);
      }
      
      ll nCrModPFermat(ll n, ll r, ll p)
      {
         if (r==0)
            return 1;
            ll fac[n+1];
            fac[0]=1;
            fac[1]=1;
            for(ll i=2;i<=n;i++) fac[i]=fac[i-1]*i%M;
          return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r], p)%p)%p;
      }
      void solve()
      {
        ll n,x,m;
        cin>>n>>x>>m;
        vector<ll> a;
        set<ll> s;
        s.insert(x);
        a.pb(x);
        ll curr=x;  
        ll flag=0;
        while(!flag)
        {
            curr=(curr*curr)%m;
            if(s.find(curr)!=s.end()){
            flag=1;
             break;

            }
            else
            {
                  a.pb(curr);
            s.insert(curr);
            }
            
        }    
        ll ind=0;
        rep(i,0,sz(a))
            if(curr==a[i])
                 {
                  ind=i;
                  break;
                 }
       ll tot=a.size();
       ll cnt=(n-ind)/(tot-ind);
       ll rem=(n-ind)%(tot-ind);
       ll ans=0;
       rep(i,0,ind) ans+=a[i];
       rep(i,ind,sz(a)) ans+=cnt*a[i];
       rep(i,ind,ind+rem) ans+=a[i];
       cout<<ans<<endl;
      

      } 
      signed main()
      {
          ios_base::sync_with_stdio(false);
          cin.tie(0);
          cout.tie(0);
          ll t=1;
          //cin>>t;
          while(t--) solve();
      }
