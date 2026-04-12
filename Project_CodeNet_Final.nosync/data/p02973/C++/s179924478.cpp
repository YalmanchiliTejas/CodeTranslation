#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long
#define vi vector<int>
#define pb push_back
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 100000000
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mk(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define ff first
#define ss second
#define re return
// #define endl "\n"
#define max2(x,y)              (x>y)?x:y
#define min2(x,y)              (x<y)?x:y
#define mid(s,e)               (s+(e-s)/2)
#define mini                   INT_MIN
#define maxo                   INT_MAX
#define rep(i,a,b) for(int i=a;i<(int)(b);++i)
#define read(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define show(a,n) for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl
#define en cout<<"\n";

int main()
{
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    vector <ll> v;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        // v.push_back(a[i]);
    }
    v.push_back(-a[0]);
    for(ll i=1;i<n;i++)
    {
        if(upper_bound(v.begin(),v.end(),-a[i])==v.end())
        {
            v.push_back(-a[i]);
        }
        else
        {
            *upper_bound(v.begin(),v.end(),-a[i])=-a[i];;
            // *itr=-a[i];
        }
    }
    cout<<v.size()<<endl;
}