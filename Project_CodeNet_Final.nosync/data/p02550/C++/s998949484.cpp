#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
#define endl "\n"
using namespace std;
const ll N=100010;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x,m;
    cin>>n>>x>>m;

    vector<ll> ar;
    vector<ll> freq(m+1,0);
    ar.pb(x);
    freq[x]=1;

    while(1)
    {
        x=(x*x)%m;
        if(freq[x]!=0){break;}
        freq[x]=1;
        ar.pb(x);
    }

    ll ans=0;
    ll idx=0;
    for(idx=0;idx<ar.size();++idx){
        if(ar[idx]==x){break;}
        ans+=ar[idx];
        --n;
        if(n==0){break;}
    }
    vector<ll> ch;
    ll sum=0;
    for(;idx<ar.size();++idx){
        ch.pb(ar[idx]);
        sum+=ar[idx];
    }
    ans+=sum*(n/ch.size());
    n=n%ch.size();
    for(ll i=0;i<ch.size();++i){
        if(n==0){break;}
        ans+=ch[i];
        --n;
        if(n==0){break;}
    }
    cout<<ans;

    return (0);
}
