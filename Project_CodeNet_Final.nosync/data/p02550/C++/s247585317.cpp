#include <bits/stdc++.h>

using namespace std;
#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
const ll maxn= 2e5+7;
const ll mod= 1e9+9 ;
const ll base=1e6+1000;


ll dd[maxn];
ll a[maxn];
ll f[maxn];
ll n1, x1, m1 ;
int sol1()
{
    ll n= n1;
    ll x=x1;
    ll m= m1;
 memset(dd,0,sizeof(dd));
     memset(a,0,sizeof(a));
     memset(f,0,sizeof(f));

     ll sum=x;
     dd[x]=1;
     ll pre=x;
     ll sl=1;
     a[sl]=x;
     f[sl]=x;

     if (x==0)
     {
         cout <<0;
         return 0;
     }
     while (1)
     {
        ll h=(pre*pre)%m;
        if (h==0||sl==n)
        {
            cout <<f[min(n,sl)];
          //  cout <<"WTF"<<endl;
            return 0;

        }
        if (dd[h])
        {
            //cout <<dd[h]<<endl;
            ll p=f[dd[h]-1];
           // cout <<sl<<endl;
            /*for (int i=1;i<=sl;i++)
            {
                cout <<a[i]<<" ";
            }
           // cout <<h<<" "<<dd[h] ;
            cout <<endl;*/
            n-=(dd[h]-1);

            ll len=sl-dd[h]+1;
            ll p1= n/len;
           ll cnt=p1*(f[sl]-f[dd[h]-1]);
           ll cl=n%len;
           cnt+=(f[dd[h]+cl-1]-f[dd[h]-1]);
           cnt+=p;
           //cout <<sl<<" "<<n<<" "<<cl<<endl ;
           cout <<cnt;
           return 0;
        }
        else
        {

            sl++;
            dd[h]=sl;
           // cout <<h<<" "<<dd[h]<<" "<<sl<<endl;
            a[sl]=h;
            f[sl]=f[sl-1]+a[sl];
            pre=h;
           // sum+=pre;
        }

     }
}
void sol2()
{
 ll n= n1;
    ll x=x1;
    ll m= m1;
    ll ans=x;

    for (int i=2;i<=n;i++)
    {
     ll h=(x*x)%m;
     x=h;
     ans+=x;
    }
    cout <<ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//freopen("test.txt","r", stdin);

    if (fopen("walk.in","r"))
    {
        freopen("walk.in","r", stdin);
        freopen("walk.out", "w",stdout);
    }

   /* srand(time(NULL));
    n1=(rand()*rand())%5;
    if (n1==0) n1+=3;
     m1=(rand()*rand())%20;
      x1=(rand()*rand())%m1;
      cout <<n1<<" "<<m1<<" "<<x1<<endl;

      sol1();
      cout <<endl;
      sol2();*/
      cin>>n1>>x1>>m1;
      sol1();

}
