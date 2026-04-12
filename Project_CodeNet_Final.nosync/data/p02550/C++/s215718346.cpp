#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    ll n,x,m;
    cin>>n>>x>>m;
    ll ans =0;
    vector<int> lasta(m+1);
    vector<ll> lastans(m+1);
    ll a = x;
    ans +=a;
    bool f=true;
    for (ll i=2;i<=n;i++)
    {
        
        a = (a*a)%m;
        if(lasta[a]==0||f==false)
        {
            lasta[a]= i;
            ans +=a;
            lastans[a] = ans;
            
        }

        else
        {
            ans +=a;
            ll loop = i - lasta[a];
            
            ll nloop = (n-i)/loop;
            ll dans = ans - lastans[a] ;

            ans +=dans *nloop;
            i += nloop * loop;
            f = false;

        }

    }
    cout<<ans<<endl;
}