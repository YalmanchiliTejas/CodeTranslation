#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RS(x) rsort(x.begin(),x,end()))
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
int INF = 1e9 + 1;
int MOD = 1e9+7;
struct initon
{
    initon()
    {
        cin.tie(0);
        ios::sync_with_stdio(false);
    };
};
signed main()
{
   int h,w,ans=0;
   cin >>h>>w;
   vector<vector<char>> a(h,vector<char>(w));
   REP(i,h){
   REP(j,w){
       cin >> a.at(i).at(j);
       if(a.at(i).at(j)=='#')ans++;
   }
   }
   if(ans==h+w-1)
   {
       cout << "Possible";
   }else{
       cout << "Impossible";
   }
}