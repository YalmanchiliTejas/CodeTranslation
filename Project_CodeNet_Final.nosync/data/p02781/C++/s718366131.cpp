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

    ll dp[1001][5];
    string s;

    void reset()
    {
        int i,j;
        for(i=0;i<=150;++i)
            for(j=0;j<=3;++j)
                dp[i][j]=-1;
    }

    ll calc(ll n,ll k)
    {
        if(k<0)
            return 0;
        if(n==0)
        {
            if(k==0)
                return 1;
            return 0;
        }
        if(k>n)
            return 0;
        if(k==0)
            return 1;
        else if(k==1)
            return n*9;
        else if(k==2)
            return n*(n-1)/2*9*9;
        else
            return n*(n-1)*(n-2)/6*9*9*9;
    }

    ll func(int i,int k)
    {
        if(k<0)
            return 0;
        if(i==s.length())
        {
            if(k==0)
                return dp[i][k]=1;
            return dp[i][k]=0;
        }
        if(dp[i][k]!=-1)
            return dp[i][k];
        if(s[i]!='0')
        {
            dp[i][k]=calc((int)(s.length())-i-1,k);
        }
        else
            dp[i][k]=0;
        for(int j=1;j<(s[i]-'0');++j)
        {
            dp[i][k]=dp[i][k]+calc(s.length()-i-1,k-1);
        }
        if(s[i]=='0')
            dp[i][k]=dp[i][k]+func(i+1,k);
        else
            dp[i][k]=dp[i][k]+func(i+1,k-1);
        return dp[i][k];
    }

    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        T=1;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            
            cin>>s;
            int n,i,j,k;
            cin>>k;
            reset();
            ll ans=0;
            ans=func(0,k);
            cout<<ans<<endl;
        }
        return 0;
    }
