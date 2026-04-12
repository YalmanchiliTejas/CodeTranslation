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
            
            int n,i,j;
            cin>>n;
            ll ar[n+1],x;
            for(i=1;i<=n;++i)
                cin>>ar[i];
            vector<ll> v;
            int q;
            for(i=1;i<=n;++i)
            {
                v.pb(ar[i]);
                q=v.size();
                while(q>2 && v[q-2]>=v[q-1] && v[q-2]>=v[q-3])
                {
                    //cout<<q<<endl;
                    x=v[q-3]+v[q-1]-v[q-2];
                    v.pop_back();
                    v.pop_back();
                    v.pop_back();
                    v.pb(x);
                    q=v.size();
                }
            }

            ll ans=0;
            int l=0,r=v.size()-1,flag=1;
            while(l<=r)
            {
                if(v[l]>v[r])
                {
                    ans=ans+flag*v[l];
                    ++l;
                }
                else
                {
                    ans=ans+flag*v[r];
                    --r;
                }
                flag=flag*-1;
            }
            cout<<ans<<endl;
        }
        return 0;
    }
