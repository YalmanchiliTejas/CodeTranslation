#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LI list<int>
#define vct vector
#define D(a) (double)(a)
#define vi vct<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vvi vct<vi>
#define vll vct<ll>
#define vvll vct<vll>
#define vpii vct<pii>
#define vpll vct<pll>
#define vb vct<bool>
#define vs vector<string>
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define ff first
#define ss second
#define bg begin()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define ft cout<<"for test"<<endl;
#define read(v,a,n) for(int i=a; i<n; i++)cin>>v[i];
#define print(v) for(auto it:v)cout<<it<<' '; cout<<endl;
#define PI 2*acos(0.0)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test,cs=1;cin>>test;while(test--)
#define rt return true
#define rf return false

///................function.....................///
#define siz(s) (int)(s.size())
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define dbg(a) cout << #a << " = " << a << " ";
///...........knight moves.....................///
///int dx[] = {+1,+1,-1,-1,+2,+2,-2,-2};
///int dy[] = {+2,-2,+2,-2,+1,-1,+1,-1};
const ll mod=1000000007;
ll lcm(ll a, ll b)
{
    return (a*b)/(ll)(__gcd(a,b));
}
int main()
{
    FIO;

    ll a=0LL,i,n,ans=0LL;
    cin>>n;
    vll v(n);
    for(i=0; i<n; i++)
    {
        cin>>v[i];
        a+=v[i];
    }
    for(i=0; i<n; i++)
    {
        a-=v[i];
        ans = (ans + ((a%mod)*v[i])%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}
