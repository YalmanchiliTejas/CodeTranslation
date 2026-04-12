#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;


#define    boost        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    nl           "\n"
#define    ll           long long
#define    pb           push_back
#define    mpr          make_pair
#define    fr(i,a,n)   for(ll i=a;i<n;++i)
#define    fr0(i,n)     for(ll i=0;i<n;++i)
#define    pii          pair<ll, ll>
#define    mem(a)       memset(a,0,sizeof(a))
const ll mod = 1000000007;

void fio()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nExecuted in: " << fixed
         << time_taken << setprecision(9);
    cout << " sec";
#endif
}



void solve(){

    // std::vector<int> v;
    // for(int i=0;i<1;i++)
    // {
    //     int x;
    //     cin>>x;
    //     v.push_back(x);

    // }

    ll n;
    cin>>n;
    ll m = pow(10,9)+7;
    ll a[n], pre[n], sum=0,ans=0;
    pre[n-1]=0;

    for(int i=0;i<n;i++)
            cin>>a[i];

    for(int i=n-2;i>=0;i--){
        pre[i]= (pre[i+1]+a[i+1]+m)%m;
        // cout<<pre[i]<<' ';
    }
    // cout<<'\n';

    for(ll i=0;i<n-1;i++){
        ll temp = ( (a[i]*pre[i]) +m )%m;
        ans= (ans+temp+m)%m;
    }

    cout<<ans;







}

int main()
{
    //auto start = chrono::high_resolution_clock::now();
    boost;
    fio();
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    //auto end = chrono::high_resolution_clock::now();
    //TIME(start, end);
    return 0;
}