//  RAKSHIT KADAM
//ALWAYS USE &IT FOR ITERATING USING AUTO ...
 #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree< int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update>
#warning !!!check the size of arrayss!!!

    #define INF 2000000000000000005
    #define MOD  1000000007
    #define newMOD  998244353
    #define MAX 300006
    #define pi 3.1415926535897932384626433832795
 
 #define ll long long
 #define int long long
 #define P(gg) for(auto rax:gg){cout<<rax<<" ";}cout<<endl;
 #define Need_for_speed(activated) ios_base :: sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
 #define satisfy ll t; cin>> t; while(t--)
 #define inp(n) int n;cin >> n
 #define mp make_pair
 #define pb push_back
 #define endl "\n"
 #define x first
 #define y second
 #define fore(i,a,b) for(ll i=a;i<b;i++)
 #define forci(i,n) for(ll i=0;i<n;i++)
 #define vi vector<ll>
 #define Endl endl
 #define lb lower_bound
 #define ub upper_bound
//#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
int power(int x, unsigned int y, unsigned int m){ if (y == 0) return 1;int p = power(x, y/2, m) % m;  p = (p * p) % m;                                                  return (y%2 == 0)? p : (x * p) % m;}
ll modInverse(int a, int m){ return power(a, m-2, m);}
ll dp[1043][4][2];
string n;ll k;
ll rec(ll f,ll ind,ll count)
{
    if(count>k)
    {
        return 0;
    }
    if(ind==n.length())
    {
        if(count==k)return 1;
        return 0;
        
    }
    if(dp[ind][count][f]!=-1)
    {
        return dp[ind][count][f];
    }
        
    ll lim;
    if(!f)lim=9;
    else
    {
        lim = n[ind]-'0';
    }
    ll ret = 0;
    for(ll i=0;i<=lim;i++)
    {
        ll newf=f;
        if(newf && i<(n[ind]-'0'))
        {
            newf&=0;
        }
        ret+= rec(newf,ind+1,((i==0)?(count):(count+1)));
        
    }
        return dp[ind][count][f]=ret;
}
void solve()
{
   cin>>n>>k;
    memset(dp,-1,sizeof dp);
    rec(1,0,0);
    cout<<dp[0][0][1]<<endl;
    
}
signed main()
{
 
   
    Need_for_speed(activated);
//satisfy
//    {
//   solve();
//    }

  //  time;
 solve();
    return 0;
}
