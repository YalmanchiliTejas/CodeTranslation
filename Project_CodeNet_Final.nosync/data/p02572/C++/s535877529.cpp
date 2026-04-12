#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))
#define pi              acos(-1.0)
#define NUM             1000000007

typedef long long ll;


int main()
{
    FastRead

    vector<ll>c;

    ll n,sum=0,ans=0;

    cin>>n;

    vector<ll>v(n);

    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
        c.push_back(sum);
    }

    for(ll i=0;i<n-1;i++)
        ans+=(((v[i]%NUM)*((sum-c[i])%NUM))%NUM)%NUM;

    ans = ans%NUM;

    cout<<ans<<endl;
}
