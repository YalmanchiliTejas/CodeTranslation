#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

void solve(int test)
{
    ll n,x,mi;
    cin>>n>>x>>mi;

    ll i,j;

    ll ans = 0;

    if(x==0){cout<<0<<endl;return;}

    if(x==1){cout<<n<<endl;return;}

    ll curr = x;

    map<ll, pair<ll,ll> >m;


    for(i=1;i<=n;i++)
    {
        if(curr==0){cout<<ans<<endl; return;}
        if(curr==1){ans = ans + (n-i+1LL);cout<<ans<<endl; return;}

        if(m.find(curr)!=m.end())
        {
           ll len = n-i+1LL;
           ll si = i - m[curr].first;
           ll div = len/si;

           ll val = ans - m[curr].second;
           val = val*div;
           ans = ans + val;
           i = i + si*div;
           break;
        }
        m[curr] = mp(i,ans);
        ans = ans +curr;
        curr = curr*curr;
        curr = curr%mi;
    }

    for(i;i<=n;i++)
    {
        if(curr==0){cout<<ans<<endl; return;}
        if(curr==1){ans = ans + (n-i+1LL);cout<<ans<<endl; return;}

        ans = ans +curr;
        curr = curr*curr;
        curr = curr%mi;
    }

    cout<<ans<<endl;

    return;
}

int main() {

 int t = 1;
// cin>>t;

 for(int x=1;x<=t;x++)
 {
    solve(x);
 }
  return 0;
}
