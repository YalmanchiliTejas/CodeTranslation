 //  RAKSHIT KADAM

 #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree< int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update>
#warning !!!check the size of arrayss!!!
 
// NUMERIC DEFINITIONS :
    #define INF 100000000000000005
    #define inf 1000000004
    #define MOD  1000000007
    #define mod 998244353
    #define MAX 300006
    #define pi 3.1415926535897932384626433832795
#define ld long double
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
#define pii pair<ll,ll>
 
 #define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout)
 #define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
int power(int x, unsigned int y, unsigned int m){ if (y == 0) return 1;int p = power(x, y/2, m) % m;  p = (p * p) % m;return (y%2 == 0)? p : (x * p) % m;}
ll modInverse(int a, int m){{ return power(a, m-2, m);}}
const int maxn = 500003;
// ll fact[1000005];
//void facto()
//{
//    ll lim =1000005;fact[0]=1;
//    for(ll i=1;i<lim;i++)
//    {
//        fact[i]=(fact[i-1]*i)%MOD;
//    }
//}
//ll ncr(ll a,ll b)
//{
//    ll ret = 0;
//    ret = fact[a]*(modInverse(fact[b],MOD));
//    ret%=MOD;
//    ret*=modInverse(fact[a-b],MOD);
//    ret%=MOD;
//    return ret;
//}

void solve()
{
     
    ll c;cin>>c;
    if(c>=30)cout<<"Yes";
    else cout<<"No";
    
}
signed main()
{
   Need_for_speed(activated);
//
//    satisfy
//    {
//        solve();
//    }
//
   
    solve();
    
    return 0;
}
//Concentrate while implementing,,,!!!
 
