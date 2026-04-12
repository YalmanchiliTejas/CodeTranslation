#include <bits/stdc++.h>

#define int long long
#define fast_io(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define us unordered_set
#define um unordered_map
#define ms multiset
#define mm multimap
#define pb push_back
#define pf push_front
#define ins insert
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define _max max_element
#define _min min_element
#define tc(T) int T; cin>>T; while(T--)
#define q(q) int q; cin>>q; while(q--)
#define pi 3.1415926535897932384626433832
const int pinf=((int)9e18);
const int ninf=((int)-9e18);
const int mod=1000000007;

using namespace std;

int32_t main()
{
    fast_io();

    //FILE *fptr1=freopen("in.txt","w",stdout);
    //FILE *fptr2=freopen("out.txt","w",stdout);


    int n;
    cin>>n;

    vector <int> a(n);
    int s=0;
    loop(i,0,n)
    {
        cin>>a[i];
        s+=a[i];
    }
    vector <int> suf(n);
    suf[n-1]=0;

    for(int i=n-2;i>=0;i--)
    {
        suf[i]=(suf[i+1]+a[i+1])%mod;
    }
    int ans=0;

    loop(i,0,n)
    {
        ans=(ans+((a[i]*(suf[i])))%mod)%mod;
    }

    cout<<ans;




    return 0;
}
