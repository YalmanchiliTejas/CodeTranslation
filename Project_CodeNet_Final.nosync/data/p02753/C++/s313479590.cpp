#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define mod 1e9+7
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rof(i,a,b) for(ll i=a;i>b;i--)

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
//memset can initialize to 0 or -1 ONLY
// memset(a,0,sizeof(a[0][0])*n*n); //2D array
//memset(a, 0, sizeof(a));  //1D array
//memset(str, 't', sizeof(str)); // string
void solve()
{
    string s;cin>>s;
    if((s[0]=='A'&&s[1]=='A'&&s[2]=='A')||(s[0]=='B'&&s[1]=='B'&&s[2]=='B'))
    cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}


int main()
{

ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
  //  cin>>t;
    while(t--)
    {
    
    solve();
    
    }

}