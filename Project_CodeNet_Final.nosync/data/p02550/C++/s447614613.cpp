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

const ll modo=998244353;
const ll ms=1e6+5;
const ll inf=1e17;


ll ar[ms];
ll mm[ms]={0};

int main()
{
    idfc;


    ll n,x,m;
    cin>>n>>x>>m;

    mm[x]=1;
    ar[1]=x;
    int i;
    int p1;
    int p2;
    for(i=2;i<=n;i++)
    {
        ar[i]=(ar[i-1]*ar[i-1])%m;
        if(mm[ar[i]])
        {
            p1=mm[ar[i]];
            p2=i;
            break;
        }
        mm[ar[i]]=i;
    }
    ll ans=0;
    ll dis;
    ll rem;
    if(i>n)
    {
     for(i=1;i<=n;i++)ans+=ar[i];
     cout<<ans;
    }
    else{
        dis=p2-p1;
        rem=(n-(p1-1))/dis;
        ll md=(n-(p1-1))%dis;
       // cout<<p2<<" "<<p1<<"\n";
      //  cout<<rem<<" "<<dis<<" "<<md<<"\n";
        for(i=1;i<p1;i++)ans+=ar[i];

        for(i=p1;i<p2;i++)
        {
            ans+=(ar[i]*rem);
        }
        for(i=1;i<=md;i++)
        {
            ans+=ar[p1];
            p1++;
        }
        cout<<ans;
    }
    return 0;
}