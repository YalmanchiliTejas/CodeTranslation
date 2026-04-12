#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define pb push_back
#define F first
#define S second
#define inf 1e18
#define mod 1000000007
#define PI 3.1415926536
#define vll vector <ll>
#define pll pair <ll,ll>
#define dbg(n) cout<<n<<' '
#define cu continue
#define br break
#define N 1000005
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s;
    cin>>s;
    ll a=0,b=0;
    for(ll i=0;i<3;i++)
    {
        if(s[i]=='A') a++;
        else b++;
    }
    if(a==0 || b==0) cout<<"No\n";
    else cout<<"Yes\n";
}