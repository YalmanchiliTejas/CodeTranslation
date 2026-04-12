#include<bits/stdc++.h>
#define ll long long int
#define Y printf("YES\n")
#define N printf("NO\n")
#define pb push_back
#define tp make_tuple
#define srt(a) sort(a.begin(),a.end())
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define pr(a) printf("%lld\n",a)
#define r0 return 0
#define pi acos(-1)

using namespace std;

int main()
{
    ll n,m,i,j,k,x,y,z,t;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>n;

    m=1e9+7;

    ll a[n+5];

    ll sum=0,ans=0;

    for(i=0;i<n;i++)
    {
        cin>>a[i];

        ans+=sum*a[i];

        ans%=m;

        sum+=a[i];

        sum%=m;
    }

    cout<<ans<<endl;



}
