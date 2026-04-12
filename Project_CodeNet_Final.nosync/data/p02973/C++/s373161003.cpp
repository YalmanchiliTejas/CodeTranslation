#include<bits/stdc++.h>
using namespace std;


#define mp make_pair
#define ll   int
#define f(i,n) for(ll i=0;i<n;i++)
#define ff(i,n) for(ll i=1;i<=n;i++)
#define  pb push_back
#define aa(s) s.begin(),s.end()
//  #define v() vector<ll>v
#define PI 3.14159265
//#define st string

// #define p 908197
//    #define mod 1000000007
#define  ti tuple
#define mod 998000099999
ll mx(ll a[],ll n)
{
    return *(max_element(a,a+n));
}
ll mi(ll a[],ll n)
{
    return *(min_element(a,a+n));
}
ll power(ll x, ll y)
{
    ll res = 1;	 // Initialize result
    x=x%mod;
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)%mod;

        // n must be even now
        y = y>>1; // y = y/2
        x = (x*x)%mod; // Change x to x^2
    }
    return res%mod;
}

void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}

ll upperIndex(ll arr[], ll n, ll y)
{
    ll l = 0, h = n;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (arr[mid] < y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
void pa(ll a[],ll n)
{
    f(i,n)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void ga(ll a[],ll n) {
    f(i, n)
        cin>>a[i];
}
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}


//long long int sum(ll i,ll j,ll l)
//{

//  return a[i][j]+a[i-l][j-l]-a[i][j-l]-a[i-l][j];
//}
//ll n,k,a,b;


//ll pre[1000000];ll suff[1000000];
/* vector<vector<ll>>a(300000);ll vis[300000];ll dist[300000];
 vector<ll>li;ll co=0;ll mxnod=-1;ll mxx=0;
 void dfs(ll st)
 {
      //cout<<st<<" ";
     //li.pb(st);
     f(i,a[st].size())
     {
         if(vis[a[st][i]]==0)
         {
             vis[a[st][i]]=1;co++;
           //  cout<<st<<" ";
                 dist[a[st][i]]=dist[st]+1;
                         if(dist[a[st][i]]>mxx)
                         {
                             mxx=dist[a[st][i]];
                             mxnod=a[st][i];
                         }
                 dfs(a[st][i]);

         }

     }


 }
 void dfs1(ll st)
 {
     //cout<<st<<" ";
     li.pb(st);
     f(i,a[st].size())
     {
         ll ch=a[st][i];

         if(dist[ch]==dist[st]-1)
         {
             //vis[a[st][i]]=1;
             //dist[a[st][i]]=dist[st]+1;
             dfs1(a[st][i]);

         }

     }


 }
 */
//ll dp[][w]={0};
/*vector<pair<ll,pair<ll,ll>>>v;ll len;
   ll dp[37][100002];
  ll solve(ll n,ll x,ll y,ll z,ll p)
  {
    if(n==len)
    {
        return 1;
    }
    if(dp[p][n]!=-1)
    {
        return dp[p][n];



    }
    ll ans=0;
    f(i,v.size())
    {
        ll x1=v[i].first;
        ll y1=v[i].second.first;
        ll z1=v[i].second.second;
        if(x!=x1 && y!=y1 && z!=z1)
        {
             ans+=solve(n+1,x1,y1,z1,i);
        }

    }
      return dp[p][n]=ans;


  }
  */
/*
    vector<ll> merge(vector<ll> v1,vector<ll> v2)
    {
        vector<ll> x;
        ll i,j,k,l,m,n,o,p,q,r,s,t;
        m=v1.size();i=0;
        n=v2.size();j=0;
        while(i<m&&j<n)
        {
            if(v1[i]<v2[j])
            {
                x.push_back(v1[i]);
                i++;
            }
            else
            {
                x.push_back(v2[j]);
                j++;
            }
        }
        while(i<m)
        {
            x.push_back(v1[i]);
            i++;
        }
        while(j<n)
        {
            x.push_back(v2[j]);
            j++;
        }
        return x;
    }
    vector<ll>sa[1000000];
    ll a[1000000];
    void build(ll s,ll e,ll i)
    {
        if(s==e)
        {
            sa[i].push_back(a[s]);
            return;
        }
        ll m=(s+e)/2;
        build(s,m,2*i+1);
        build(m+1,e,2*i+2);
        sa[i]=merge(sa[2*i+1],sa[2*i+2]);
    }
    ll query(ll s,ll e,ll l,ll r,ll i,ll x1,ll x2)
    {
        if(e<l || r<s || s>e)
            return 0;
        if(s>=l && e<=r)
        {
            ll v1= upper_bound(sa[i].begin(),sa[i].end(),x1)-sa[i].begin();
           // ll v2= lower_bound(sa[i].begin(),sa[i].end(),x2-1)-sa[i].begin();
            return v1;
        }
        ll m=(s+e)/2;
        ll ls=query(s,m,l,r,2*i+1,x1,x2);
        ll rs=query(m+1,e,l,r,2*i+2,x1,x2);
        return ls+rs;
    }
*/

/*  class ss
  {
int x;
  public:
      ss(int i)
      {
          x=i;
          cout<<"jell"<<" "<<x;
      }


  };
*/

//vector<vector<pair<ll,ll>>>a(500006);
//ll dist[100000],vis[100000];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;cin>>n;
    ll a[n];f(i,n)cin>>a[i];

    ll ans=0;
    //ll maxi=10000000000;
   multiset<ll>s;
    f(i,n)

    {

        if(i==0)
        {
            s.insert(a[i]);ans++;
        } else
        {
            auto itr=s.begin();
            if(a[i]<=*itr)
            {
                s.insert(a[i]);
                ans++;
            } else
            {
                auto x=s.lower_bound(a[i]);
                x--;
                s.erase(x);
                s.insert(a[i]);
               // *x=a[i];
            }


        }

    }

cout<<ans;
//cout<<-1%2;
}