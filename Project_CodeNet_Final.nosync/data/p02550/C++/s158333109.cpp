#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10
#define ll long long
#define double long double
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define all(a) (a).begin(), (a).end()
#define sz size
#define f first
#define s second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define pi pair
#define rc(s) return cout<<s,0
#define endl '\n'
#define mod 1000000007
#define PI 3.14159265359
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005ll
#define CODE_START  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll n,x,m,a[200005],k=0,ans=0;
map<ll,ll>viz;
int32_t main(){
CODE_START;
cin>>n>>x>>m;
if(n==1){
cout<<x;
return 0;
}
ans+=x;
x%=m;
viz[x]=1;
a[++k]=x;
for(ll i=2;i<=n;i++)
{
    x*=x;
    x%=m;
        if(viz[x]!=0){
               // cout<<i<<endl;
            vector<ll>v;
            for(ll j=viz[x];j<i;j++)
            {
                v.pb(a[j]);
            }
            n-=i;
        n++;
            ll nr=n/int(v.size());
            ll sum=0;
            for(ll j=0;j<v.size();j++)
            {
                sum+=v[j];
            }
            ans+=sum*nr;
            ll pos=n%int(v.size());
            sum=0;
            for(ll j=0;j<pos;j++)
            {
                sum+=v[j];
            }
            ans+=sum;

        break;
    }
    ans+=x;
    viz[x]=i;
    a[++k]=x;
}
cout<<ans<<endl;
}
