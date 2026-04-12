    #include<bits/stdc++.h>
    #define int ll
    #define M 1000000007
    #define hell 998244353
    #define inf 1e18
    #define pb push_back
    #define pi 3.1415926536
    #define mp make_pair
    #define ub upper_bound
    #define lb lower_bound
    #define all(a) a.begin(),a.end()
    #define ll long long
    #define vec vector <int>
    #define pii pair<int,int>
    #define endl "\n"
    #define gcd __gcd
    using namespace std;
    int power(int x, unsigned int y, unsigned int m) 
    { 
        if (y == 0) 
            return 1; 
        int p = power(x, y/2, m) % m; 
        p = (p * p) % m; 
  
        return (y%2 == 0)? p : (x * p) % m; 
    } 
    int modInverse(int a, int m) 
    {   
        return power(a, m-2, m);
    }
    int nCrModPFermat(int n, int r, int p) 
    { 
           if (r==0) 
              return 1; 
  
        int fac[n+1]; 
        fac[0] = 1; 
        for (int i=1 ; i<=n; i++) 
            fac[i] = fac[i-1]*i%p; 
  
        return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
    } 
    signed main()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll t=1;
        // cin >> t;
        /*SAARE INPUTS LENA*/
        /*VARIABLES KI RANGE DEKHLENA*/
        /*EXPONENT RANGE OF OUTPUT KA DHYAN RAKHNA*/
        while(t-->0)
        {
            ll n=0,s=0,ans=0;
            cin>>n;
            vector <int> v(n),su(n);
            for (int i = 0; i < n; ++i)
            {
                cin>>v[i];
                s+=v[i];
                if(i==0)
                    su[0]=v[i];
                else
                    su[i]=su[i-1]+v[i];
            }
            for (int i = 0; i < n; ++i)
            {
                int k=(v[i]*((s-su[i])%M))%M;
                ans+=k;
                ans%=M;
            }
            cout<<ans;

        }
        return 0;
    }
