    //For higher stack size use g++ -O2 -std=c++11 -Wall -Wl,--stack=268435456 a.cpp -o a.exe in cmd
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define ll long long
    #define ld long double
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define pb push_back
    #define f first
    #define s second
    
    using namespace std;

    ll fact[200001],inv[200001],ct2[200001];

    ll power(ll a, ll b)    //a is base, b is exponent
    {
        if(b==0)
            return 1;
        if(b==1)
            return a;
        if(b%2 == 1)
            return (power(a,b-1)*a)%mod;
        ll q = power(a,b/2);
        return (q*q)%mod;
    }

    void init()
    {
        fact[0]=inv[0]=1;
        for(int i=1;i<=200000;++i)
        {
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=power(fact[i],mod-2);
        }
    }

    ll ncr(int n,int r)
    {
        if(n<r)
            return 0;
        return ((fact[n]*inv[n-r])%mod*inv[r])%mod;
    }

    ll sum(ll x)
    {
        ll ans=x*(x+1)/2;
        return ans%mod;
    }


    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        T=1;
        init();
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            ll n,m,k,i,j,ct,sum2=0,ans=0,z,ans2=0;
            cin>>n>>m>>k;
            if(n>m)
                swap(n,m);
            sum2=0;
            for(i=1;i<=m;++i)
            {
                sum2=(sum2+sum(m-i)+sum(i-1))%mod;
            }
            sum2=(sum2*power(2,mod-2))%mod;
            for(i=1;i<=n;++i)
            {
                j=i;
                ans=(ans+((m*m)%mod*(j-i))%mod+sum2)%mod;
                for(j=i+1;j<=n;++j)
                {
                    ans=(ans+((m*m)%mod*(j-i))%mod+2*sum2)%mod;
                }
                //cout<<i<<" "<<ans<<endl;
            }
            ans=(ans*ncr(n*m-2,k-2))%mod;
            cout<<ans<<endl;
        }
        return 0;
    }
