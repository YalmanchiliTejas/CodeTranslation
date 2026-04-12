#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define rep(i,l,r) for(int i=l;i<r;i++)
#define bep(i,l,r) for(int i=l;i>=r;i--)
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define el '\n'
#define sz(s) s.size()
#define all(v) v.begin(),v.end()
#define mii map<int,int>
#define mr  make_pair

int mod = 1e9+7;
int inf = 1e18;
const int N = 3e5+5;
int powmod(int a,int b) {int res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
signed main()
{
    io
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
      string s;
      cin>>s;
      int a = 0;
      int b =  0;
      rep(i,0,3)
      {
          if(s[i]=='A')
            a++;
          else
            b++;
      }
      if(a==3||b==3)
        cout<<"No";
      else
        cout<<"Yes"<<el;


    }

    return 0;
}
