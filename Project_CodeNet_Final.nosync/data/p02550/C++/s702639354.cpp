#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define mod 998244353
ll a[2000005],dp[2000005];
int main()
{
    /*string s;
    cin >> s;
    int n = s.size();
    if(s[n-1]=='s')
        s+="es";
    else
        s+="s";
    cout <<s << endl;*/
    /*int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i];

    int f=0;
    for(int i=1;i<=n-2;i++)
    {
        if((a[i]==b[i])&&(a[i+1]==b[i+1])&&(a[i+2]==b[i+2]))
        {
            f=1;
            break;
        }
    }
    if(f) cout << "Yes\n";
    else
        cout << "No\n";*/;
    /*ll n;
    cin >> n;
    ll ans=0;
    for(ll i=1;i<n;i++)
        ans+= (n-1)/i;

    cout << ans << endl;*/


    /*ll n,k;
    cin >> n>>k;
    set<ll>st;
    for(ll i=0;i<k;i++)
    {
        ll x,y;
        cin >> x>> y;
        for(ll j=x;j<=y;j++)
            a[j]=1;
    }
    vector<ll>v;
    dp[1]=1;
    for(ll i=1;i<=n;i++)
    {
        if(a[i])
            v.push_back(i);
    }
    sort(v.begin(),v.end());
    ll sz = v.size();
    for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<sz;j++)
            {
                if(i>=v[j])
                {
                    dp[i]=(dp[i]+dp[i-v[j]])%mod;
                }
                else
                    break;
            }
        }
    cout << dp[n] << endl;*/

    ll n, x,m;
    cin >> n >> x >> m;
    ll ans=x;
    dp[1]= x;
    ll mn = min(n,m);
    for(ll i=2;i<=mn;i++)
    {
        dp[i] = (dp[i-1]*dp[i-1])%m;
        ans+= dp[i];

    }
    //cout << ans << endl;
    if(n>m)
    {
        ll id;
        ll p  = (dp[mn]*dp[mn])%m;
        for(ll i=1;i<=mn;i++)
        {
            if(dp[i]==p)
            {
                id = i;
                break;
            }
        }
        //cout << id <<  endl;
        ll tot = mn-id+1;
        ll sum=0;
        for(ll i= id;i<=mn;i++) sum+= dp[i];
        n = n-m;
        ll vag = n/tot;
        ans+= (sum)*vag;
        ll rem= n%tot;
        if(rem!=0){
            for(ll i = id;;i++)
            {
                ans+= dp[i];
                rem--;
                if(rem==0) break;
            }
        }
    }
    cout << ans << endl;


}
