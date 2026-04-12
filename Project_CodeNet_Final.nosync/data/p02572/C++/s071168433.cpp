#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
//:/
#define pb push_back
#define mp make_pair
#define nt _ll128
#define ld double
long double PI =3.14159265;
using ll = long long;

const ll modo=1e9+7;
const ll ms=1e5+5;
const ll inf=1e17;




int main()
{
    idfc;


    ll ans=0;
    ll c=0;

    ll n;
    cin>>n;
    ll e;
    ll i;
    ll tmp;
    for(i=1;i<=n;i++)
    {
        cin>>e;
        tmp=(e*c)%modo;
        ans=(ans+tmp)%modo;
        c=(c+e)%modo;
    }
    cout<<ans;


    return 0;
}