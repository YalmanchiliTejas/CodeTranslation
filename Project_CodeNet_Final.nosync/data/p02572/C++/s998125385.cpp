#include <bits/stdc++.h> 
    #include<ext/pb_ds/assoc_container.hpp> 
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    template <typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    #define int long long  
    typedef long double ld;
    #define pb push_back
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define fd(i,a,b) for(int i=a-1;i>=b;i--)
   #define print(a,n) f(i,0,n){cout<<a[i]<<" ";}
    #define pf push_front
    #define fi first
    #define se second
    #define ps(x,y)         fixed<<setprecision(y)<<x
    #define INF 1e10
    const double pi=3.14159265358979323;
    const int mod=1e9+7;
    const int MAX=1000000+5;
    int p[MAX]={0};

     int gcd(int a, int b) 
    { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
    } 
    void swap(int a,int b)
    {
      int temp=a;
      a=b;
      b=temp;
    } 
    int  binpow(int  a,int  b) 
    {
    int res = 1;
    while (b > 0) {
        if (b%2 == 1)
            res = (res * a)%mod;
        a = (a* a)% mod;
        b >>= 1;
    }
    return res;
}
    int modinv(int y)
    {
        return binpow(y,mod-2);
    }

    int fact[500000+5];
    void precal()
    {
    fact[0]=1;
    for(int i=1;i<500000+5;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
}
    bool isPrime(int n) 
    { 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
   
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
    } 
    int mm[200000+5]={0};
    int pos[200000+5]={0};
    int pr[200000+5]={0};
    vector<pair<int ,int>> vv;
    int cnt=0;
    int vis[200000+5]={0};
     vector<vector<int >> adj;
        void dfs(int j,int x,int cnt)
        {
            vis[j]=1;
            pr[j]=x;
            vv.pb({-1*cnt,j});
            for(auto i:adj[j])
            {
                if(vis[i]==0)
                    dfs(i,j,cnt+1);
            }
        }
        void bfs(int j)
        {
            vis[j]=1;
            queue<int > q;
            q.push(j);
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                for(auto i:adj[x])
                {
                    if(vis[i]==0)
                    {
                    vis[i]=1;
                    q.push(i);
                    }
                 }    
            }
        }
        int pre[3002][3002]={};
    signed main() {

 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout); 
      }
    #endif  
    // -------------------------------------Code starts here--------------------------------------------------------------------- 
    int t=1; 
    //cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int a[n];
       f(i,0,n)
       cin>>a[i];
       int suff[n+1]={0};
       fd(i,n,0)
       {
            suff[i]=(suff[i+1]+a[i])%mod;
       }
       int ans=0;
       f(i,0,n)
       {
            ans=(ans+((suff[i+1])*a[i])%mod)%mod;
       }
       cout<<ans<<endl;
    }
}

