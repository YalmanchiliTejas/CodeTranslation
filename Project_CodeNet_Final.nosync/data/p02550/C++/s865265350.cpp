#include<bits/stdc++.h>

typedef   long long  int ll;
typedef  long double ld;
typedef std::vector<ll> vi;
typedef std::vector<std::vector<ll> > vv;

#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,b) for(i=a;i<b;i++)
#define mp make_pair
#define pb(x) push_back(x)
#define fi first
#define se second
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" ";cout<<"\n";
#define all(a) a.begin(),a.end()
#define input(vec,a,b) for(ll i = a;i<b;i++) cin>>vec[i];
#define ms(a,val) memset(a,val,sizeof(a))
using namespace std;

const int N = 1e5 + 5;


void solve(){
            ll i,j,n,x,m;
            cin>>n>>x>>m;
            vi vis(m,0);
            ll temp = x;
            ll sum = 0;
            ll count = 1;
            vi sise(m,0),val(m,0);
            while(count<=n&&vis[temp]==false)
            {
                vis[temp] = 1;
                sise[temp] = count;
                count++;

                val[temp] = sum;
                sum+=temp;
                temp = ((temp%m)*(temp%m))%m;



            }
            if(count>n)
             cout<<sum<<endl;
            else{
                ll ans = val[temp];
                n-=(sise[temp] - 1);
                ll cycle = sum - val[temp];
                ll len = count - sise[temp];
                ans+=((n/len)*cycle);
                count =(n/len)*len;
                while(count<n)
                {
                    ans+=temp;
                    temp =((temp%m)*(temp%m))%m;
                    count++;
                }
                cout<<ans<<endl;

            }







}

int main()
{

      ll t=1,i;
      //cin>>t;

            while(t--)
      {

          solve();
      }
    return 0;
}
