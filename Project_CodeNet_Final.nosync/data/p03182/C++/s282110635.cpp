#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back

typedef long long LL;
typedef  pair<int,int > PII;

const double PI = acos(-1.0);
//const int INF = 1000 * 1000 * 1000 + 1;
const LL INF = 1e15 + 7;
const int MAS =4e5; //5;
const int MOD = 998244353;
const double EPS = 1e-8;


typedef vector<int > VI;
typedef vector<LL> VL;



VL t;
VL lazy;

void update(int v, int tl, int tr  ,int l ,int r,LL val )
{
     if (lazy[v]!=0)
     {
         t[v]+=lazy[v];
         if(tl !=tr)
         {
             lazy[v * 2 ] +=lazy[v];
             lazy[v * 2 + 1] +=lazy[v];
         }
         lazy[v] = 0;
     }
      if ( l<=tl && r >=tr)
      {
          t[v] += val;
          if(tl !=tr)
          {
              lazy[v * 2] +=val;
              lazy[v * 2 +1] +=val;
          }
          return ; 
      }
    if ( tr < l || tl > r)return ;
    int tm  = (tl + tr)/2;
     update(v * 2 , tl , tm , l ,r ,val);
     update(v * 2 + 1, tm  +1 ,tr, l ,r ,val);
     t[v] = min(t[v* 2],t[v * 2 +1]);
}
LL  mn (int v ,int tl ,int tr ,int l ,int r )
{
     if (lazy[v] !=0)
     {
         t[v] +=lazy[v];
         if(tl !=tr)
         {
             lazy[v * 2] +=lazy[v];
             lazy[v * 2 + 1] +=lazy[v];
         }
         lazy[v] = 0;
     }
     if (tl > r || tr < l )
     {
         return INF;
     }
     if(l <=tl && r >=tr)
     {
         return t[v];
     }
     int tm = (tl + tr)/ 2;
     return min(mn(v * 2 ,tl ,tm, l ,r ),mn (v* 2 +1 ,tm + 1, tr, l ,r )) ;
}


int main() {
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);

    IOS;
     int n,m ;
     cin >> n  >> m ;
     LL sum = 0 ;
     vector<vector<pair<int,int >>> ev(n + 5);
     rep(i,m)
     {
         int l ,r ,val;
         cin >> l >> r >> val;
         ev[r].PB({l,val});
         sum+=val;
     }
     LL ans =0 ;
  //   return 0 ;
       t.resize(4 * (n + 5 )  ,INF);
       lazy.resize(4 * (n +5 ) );
     //  return 0;
       update(1, 0, n, 0 , 0 ,-INF);
    // cout <<  mn( 1, 0 , n -1 , 0 , n-1 ) << endl;
    // return 0 ;
     FOR(i,1,n +2)
     {
         for(pair<LL,LL> p : ev[i-1])
         {
             update(1,0,n,0,p.first - 1 ,p.second);
         }
         LL best = mn(1, 0 , n , 0 , n );
      //   cout << i << " " << best  << " " ;
         if( i == n + 1)
         {
             ans = best;
         }
         update(1,0,n,i,i,best - INF);
       //  cout <<  mn (1, 0 , n , 0 ,n ) << endl;
     }
    // cout << ans << endl;
    cout << sum - ans;
}