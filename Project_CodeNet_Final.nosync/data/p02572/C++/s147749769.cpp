            #include<bits/stdc++.h>
            #define ll long long
            #define f   first
            #define s   second
            #define pb          push_back
            #define mod        1000000007
            #define mod1       1000000009
            #define hell        998244353
            #define inf         1000000000000000000LL
            #define pi          3.14159265358979323
            //#define N           100005 
            const int N=1000005;
            using namespace std;
            ll n,k,sum,q,res,m,val,ans;
            ll x,y;
            double p;
            ll xx[]={1,0,-1,0};
            ll yy[]={0,1,0,-1};
            void solve()    
            {   ll a,b,c;
                cin>>n;
                vector<ll> v(n);
                for(int i=0;i<n;i++) cin>>v[i];
                ll suf[n];
                suf[n-1]=v[n-1];
                for(int i=n-2;i>=0;i--) suf[i]=(suf[i+1]+v[i])%mod;
                ll ans=0;
                for(int i=0;i<n-1;i++)
                {
                    ll res=(v[i]*suf[i+1])%mod;
                    ans+=res;
                    ans%=mod;
                }
                cout<<ans;

                
                
            }
            int main()  
            {   ios_base::sync_with_stdio(false);
                cin.tie(0);cout.tie(0);
                ll t=1;
                
                //cin>>t;
                 for(ll i=1;i<=t;i++)
                    solve();
                
            }            
