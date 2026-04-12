/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    ll n,x,m;
    cin>>n>>x>>m;
    ll sum=x;
    vector<ll> v;
    map<ll,ll> mark;
    v.pb(sum);
    mark[sum]=1;
    ll len=1;
    for(ll i=2;i<=min(n,m);i++){
        ll cur=sum;
        sum=sum*sum;
        sum=(sum%m);
        if(mark.find(sum)!=mark.end()){
            len=mark[sum];
            //v.pb(sum);
            break;
        }
        else{
            mark[sum]=i;
            v.pb(sum);
        }
    }

    //for(ll i:v) cout<<i<<" "; cout<<endl;
    len--;
    //cout<<len<<endl;
    //for(ll i:pat) cout<<i<<" "; cout<<endl;

    n-=(len);

    ll d=n/(v.size()-len);
    ll r=n%(v.size()-len);

    //cout<<d<<" "<<r<<endl;

    ll res=0;
    for(ll i=0;i<len;i++) res+=v[i];

    for(ll i=len;i<v.size();i++) res=(res+v[i]*d);
    for(int i=len;i<len+r;i++) res+=v[i];

    cout<<res<<endl;


    return 0;
}


