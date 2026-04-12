    #include<bits/stdc++.h> 
    using namespace std;
    typedef long long ll;
    const int N=2e5+5;
    const int mod=1e9+7;
    ll ans;
    int n;
    ll A[N];
    ll B[N];
    int main()
    {
        ios::sync_with_stdio(false);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
            B[i]=B[i-1]+A[i];
        }
        for(int i=1;i<=n;i++)
            ans=(ans+(A[i]*((B[n]-B[i])%mod))%mod)%mod;
        cout<<ans<<endl;
    }