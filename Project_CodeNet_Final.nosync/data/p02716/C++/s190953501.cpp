#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int n;
int a[200001];
map<pair<pair<int,int>,int>,int>m;
int solve(int index,int last_selected,int selected)
{
    int idx=index-1;
    if(index==n+1)
    {
        if(selected==n/2)
            return 0;
        else
            return -1e15;
    }
    if(m.count({{index,last_selected},selected}))
        return m[{{index,last_selected},selected}];
   if((n/2)-((n-idx+1)/2)<=selected)
   {

       if(last_selected)
          return  m[{{index,last_selected},selected}]=solve(index+1,false,selected);
       else
           return m[{{index,last_selected},selected}]=max(solve(index+1,true,selected+1)+a[index],solve(index+1,false,selected));
   } else
       return -1e15;

}
int32_t main() {
    nitin;
    cin>>n;
    ci(n) cin>>a[i+1];
    cout<<solve(1,false,0);
    return 0;
}