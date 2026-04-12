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
//
//template<typename... T>
//void write(T&... args)
//{
//    ((cout << args << ' '), ...);
//}
//ll power ( ll x , ll y)
//{
//    ll res = 1;
//    while (y > 0)
//    {
//        if (y & 1)
//            res = (res * x) ;
//        y = y >> 1;
//        x = (x * x) ;
//    }
//    return res  ;
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
// }
//
//ll sev[100006];
//vector<ll> pri;
//void seive()
//{
//    for(ll i = 2 ; i < 100006 ; i ++)
//    {
//        if(!sev[i])
//        {
//            for(ll j = i ; j < 100006 ; j += i)
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
    string str;
    cin >> str;
    ll k , ans = 0;
    cin >> k;
    if(str.size() < k)
    {cout << 0 << '\n';return;}
    if(k == 1)
    {
        ll zz = str.size();
        ans += (zz - 1) * 9;
        ans += str[0] - '0';
        cout << ans << '\n';
        return;
    }
    else if(k == 2)
    {
        ll zz = str.size();
        for(ll j = 1 ; j < zz ; j ++)
        {
            ll temp = zz - j ;
            if(temp > 0)
            ans += (temp - 1) * 9 * 9;
            ll f1 = 0;
            for(ll oi = j - 1 ; oi > 0 ; oi --)
                f1 += str[oi] - '0';
            if(f1)
                ans += (((str[0] - '0') - 1)) * 9 + 9;
            else
               ans += ((str[0] - '0') - 1) * 9 + (str[j] - '0');
            //cout << ans << ' ' ;
        }
        cout << ans << '\n';
        return;
    }
    else{
        ll zz = str.size() , ans = 0;
        //cout << zz << '\n';
        for(ll i = 1 ; i < zz - 1; i ++)
        {
            for(ll j = i + 1 ; j < zz ; j ++)
            {
                
                ll temp = zz - j ;
                if(temp > 0)
                    ans += (temp - 1) * 9LL * 9LL * 9LL;
                //cout << ans << ' ';
                ll f1 = 0, f2 = 0;
                
                for(ll oi = i - 1 ; oi > 0 ; oi --)
                    f1 += (str[oi] - '0');
                for(ll oi = j - 1 ; oi > i ; oi --)
                    f2 += (str[oi] - '0');
                if(f1 > 0)
                    ans += ((str[0] - '0')) * 9 * 9;
                else if(f2 > 0)
                {
                    ans += (((str[0] - '0') - 1)) * 9 * 9 + ((str[i] - '0')) * 9;
                }
                else{
                    ans += (((str[0] - '0') - 1) * 9 * 9) ;
                //cout << ans << ' ';
                    if((str[i] - '0') != 0 && (str[j] - '0') != 0)
                        ans += ((((str[i] - '0') - 1) * 9) + (str[j] - '0'));}
                  //  cout << ans << endl;}
            }
        }
        cout << ans << '\n';
        
        }
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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
 
