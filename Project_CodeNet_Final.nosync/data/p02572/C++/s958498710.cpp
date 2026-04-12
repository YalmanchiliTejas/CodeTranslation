#include <bits/stdc++.h>
   
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << "=" << x << endl
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define vi vector<int>
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define mod 1000000007
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define int long long
const int N=1e5+5;



void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(auto &x:a)cin>>x;
    vector<int>v;
    for(auto x:a)v.pb(x);
    for(int i=n-2;i>=0;i--)a[i]+=a[i+1];
    
    for(int i=0;i<n;i++)a[i]%=mod;
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i+1<n)
        {
            int t=(v[i]*a[i+1]);
            ans+=t;
            ans%=mod;
        }
    }
    cout<<ans;
    
}

int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
//	cin>>t;
	while(t--)solve();
	    
  
}


