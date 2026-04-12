#define ll long long int
#include <bits/stdc++.h>
//#include <fstream>
using namespace std;
 
#define         ff               first
#define         ss               second
#define         mp               make_pair
#define         pb               push_back
#define         pf               push_front
#define         vi               vector<ll>
#define         pii              pair<ll,ll>
#define         qi               queue<ll>
#define         mem(a,b)         memset(a,b,sizeof(a))
#define         print(a)         cout<<a<<'\n'
#define         sorted(arr)      sort(arr.begin(),arr.end())
#define         gcd(a,b)         gcd((a),(b))
#define         lcm(a,b)         ((a)*(b))/gcd((a),(b))
#define         all(v)           v.begin(),v.end()
#define         read(a)          scanf("%d", &a)
#define         f(a,n)           for(ll i=a;i<n;i++)
#define         in2(n,m,arr)     for(ll i=0;i<n;i++){for(ll j=0;j<m;j++)cin>>arr[i][j];}
#define         debug(a)         cerr<<a<<" ";
#define         debug1(a)        cerr<<a<<'\n'
 
/*typedef tree<int, null_type, less<int>, rb_tree_tag , tree_order_statistics_node_update> Set;*/
 
 
const unsigned ll mod = 1e9 + 7 ;
const ll inf = (ll)1e18 + 2;
const ll N = (ll)1e6 + 2;
 
//template<typename... T>
//void write(T&... args)
//{
//    ((cout << args << ' '), ...);
//}
//ll power ( ll x , unsigned ll y)
//{
//    ll res = 1;
//    while (y > 0)
//    {
//        if (y & 1)
//            res = (res * x) % mod ;
//        y = y >> 1;
//        x = (x * x) % mod;
//    }
//    return res % mod ;
//}
//
//struct node{
//    ll x , y , z;
//};
//map<pair<ll, ll>,ll> c;
//vector<set<ll>> tree;
//vector<ll> ar ;
//set<ll> s;
//ll get(ll x)
//{
//    if(x == ar[x])
//        return x;
//    return ar[x] = get(ar[x]);
//}
//void merge(ll a ,ll b)
//{
//    a = get(a);
//    b = get(b);
//    if(a == b)
//    {
//        return ;
//    }
//    ar[b] = ar[a];
//    //ans[a] += ans[b];
//    //return true;
// }
//
//ll sev[275];
//vector<ll> pri;
//void seive()
//{
//    for(ll i = 2 ; i < 275 ; i ++)
//    {
//        if(!sev[i])
//        {
//            for(ll j = i ; j < 275 ; j += i)
//            {
//                if(!sev[j])
//                    sev[j] = i;
//            }
//        }
//        if(sev[i] == i)
//            pri.pb(i);
//    }
//}
void solve()
{
    ll n ,m ;
    cin >> n >> m;
    if(n == m)
        print("Yes");
    else
        print("No");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t ;
    t = 1;
    //cin >> t;
    //seive();
    while(t --)
    {
        solve();
    }
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
 
