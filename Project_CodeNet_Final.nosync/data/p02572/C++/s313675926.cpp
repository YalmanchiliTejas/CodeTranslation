#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout);
#define pb push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sl2(x,y) scanf("%lld %lld",&x,&y)

#define sl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sd(x) scanf("%lf",&x);
#define pLL pair<long long,long long>
#define pDB pair<double,double>
#define ff first
#define sn second
#define PRINT_CASE  printf("Case %d: ",tc++)
#define PRINT_CASENL  printf("Case %d:\n",tc++)
//#define mx 100005
#define lnd tree[ind<<1]
#define rnd tree[(ind<<1)+1]
#define cnd tree[ind]
#define lndp b,(b+e)>>1,(ind<<1)
#define rndp ((b+e)>>1)+1,e,(ind<<1)+1
#define IN(a,x,y) (a>=x && a<=y)
#define popcountL __builtin_popcountll
#define popcount __builtin_popcount
/// int other=mask^((1<<n)-1);
typedef long long ll;
typedef long long int lln;
typedef pair<int,int> pii;
ll INF=1<<28;
//typedef long long lld;
const double PI=acos(-1.0);
//int fx[]={1,-1,0,0}; //direction array
//int fy[]={0,0,1,-1};
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int knight[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
const long double EPS=1e-7;
//#define INF 10000

struct compare
{
  bool operator()(const pair<int,pii>& l, const pair<int,pii>& r)
  {
      if(l.ff==r.ff)
      {
          return l.sn.ff>r.sn.ff;
      }
      return l.ff<r.ff;
  }
};
// bool operator<(pair<int,pii> l, pair<int,pii> r)
//  {
//      if(l.ff==r.ff)
//      {
//          cout<<"ok "<<endl;
//          return l.sn.ff<r.sn.ff;
//      }
//      return l.ff>r.ff;
//  }

/////////////////////////////////////template sesh/////////////////////////////////////////////////////

///code goes from here
const int mx=300015;
///
int mod=1e9+7;
ll arr[mx];
int main()
{
//    SPEED;
    int t,tc=1;
    t=1;
    while(t--)
    {
        int n;
        sf(n);
        for(int i=0;i<n;i++)
        {
            sl(arr[i]);
        }
        ll sum=0;
        ll ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=((sum*arr[i])%mod);
            ans%=mod;
            sum+=arr[i];
            sum%=mod;
        }

        cout<<ans<<endl;

    }



    return 0;
}

