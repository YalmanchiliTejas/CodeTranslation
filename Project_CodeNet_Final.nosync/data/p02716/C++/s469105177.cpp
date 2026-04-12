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
    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        T=1;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            ll n,i,j;
            cin>>n;
            ll ar[n+1],ans=-1e15;
            for(i=1;i<=n;++i)
            {
                cin>>ar[i];
            }
            if(n%2==0)
            {
                ll dp[n+3],dp2[n+3],sum=0,sum2=0,mini=1e15,mini2=1e15;
                dp[n+2]=0,dp[n+1]=0,dp2[n+1]=0,dp2[n+2]=0;
                for(i=n;i>=1;--i)
                {
                    if(i%2==1)
                    {
                        dp[i]=dp[i+1]+ar[i];
                        dp[i]=max(dp[i],ar[i]+dp2[i+3]);
                        dp2[i]=dp2[i+1];
                    }
                    else
                    {
                        dp2[i]=dp2[i+1]+ar[i];
                        dp[i]=dp[i+1];
                    }
                }
                ans=max(dp[1],dp2[1]);
            }
            else
            {
                ll dp[n+3],dp2[n+3],sum=0,sum2=0,mini=1e15,mini2=1e15;
                dp[n+2]=0,dp[n+1]=0,dp2[n+1]=0,dp2[n+2]=0;
                for(i=n;i>=1;--i)
                {
                    if(i%2==1)
                    {
                        dp[i]=dp[i+1]+ar[i];
                        dp2[i]=dp2[i+1];
                    }
                    else
                    {
                        dp2[i]=dp2[i+1]+ar[i];
                        dp2[i]=max(dp2[i],ar[i]+dp[i+3]);
                        dp[i]=dp[i+1];
                    }
                }
                for(i=1;i<=n;++i)
                {
                    if(i%2==1)
                    {
                        ans=max(ans,sum+dp2[i+1]);
                        ans=max(ans,sum+dp[i+2]);
                    }
                    else
                    {
                        ans=max(ans,sum2+dp[i+1]);
                    }
                    // cout<<i<<" "<<dp[i]<<" "<<dp2[i]<<" "<<" "<<sum<<" "<<sum2<<" "<<ar[i]<<" "<<ans<<endl;
                    if(i%2==1)
                    {
                        mini=min(mini,ar[i]);
                        sum=sum+ar[i];
                        if((i+3)<=n+2)
                        {
                            ans=max(ans,sum+dp2[i+3]);
                        }
                    }
                    else
                    {
                        mini2=min(mini2,ar[i]);
                        sum2=sum2+ar[i];
                        if((i+3)<=n+2)
                        {
                            ans=max(ans,sum2+dp[i+3]);
                        }
                    }
                    // cout<<i<<" "<<dp[i]<<" "<<dp2[i]<<" "<<" "<<sum<<" "<<sum2<<" "<<ar[i]<<" "<<ans<<endl;
                }
                // cout<<sum<<" "<<sum2<<" "<<mini<<" "<<mini2<<endl;
                ans=max({ans,sum-mini});
            }
            cout<<ans<<endl;
        }
        return 0;
    }
