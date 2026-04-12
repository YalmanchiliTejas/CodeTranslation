#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define     bit_1(a)       __builtin_popcount(a)
#define     ull            unsigned long long
#define     ll             long long
#define     u              unsigned
#define     pb             push_back
#define     pf             push_front
#define     mpr            make_pair
#define     ins            insert
#define     ff             first
#define     ss             second
#define     vi             vector<int>
#define     vl             vector<ll>
#define     vstr           vector<string>
#define     si             set<int>
#define     sl             set<ll>
#define     li             list<int>
#define     pii            pair<int,int>
#define     pll            pair<ll,ll>
#define     mii            map<int,int>
#define     mll            map<ll,ll>
#define     ma             INT_MAX
#define     mi             INT_MIN
#define     mod            1000000007
#define     pi             3.14159265359
#define     e              2.71828182846
#define     inf            1000000000000000LL
#define     all(x)         x.begin(), x.end()
#define     lb(a,b,c)      lower_bound(a,a+b,c)-a
#define     ub(a,b,c)      upper_bound(a,a+b,c)-a
#define     lbv(a,c)       lower_bound(all(a),c)-a.begin()
#define     ubv(a,c)       upper_bound(all(a),c)-a.begin()
#define     srt1(a,b)      sort(a,a+b)
#define     srt2(a,b)      sort(a,a+b,greater<int>())
#define     gcd(a,b)       __gcd(a,b)
#define     lcm(a,b)       (a*(b/gcd(a,b)))
#define     harmonic(n)    0.57721566490153286l+log(n)
#define     mem(a, b)      memset(a, b, sizeof(a))
#define     orderset1      tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define     orderset2      tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>

///s.lower_bound(a),s.upper_bound(a), for set
///nCr(x, y) = nCr(x-1, y-1) + nCr(x-1, y)
///factorial digit   ((n * log10(n / e) +log10(2 * pi * n) /2.0));
/// lcm(a,b)=a/gcd(a,b)*b (handle overflow)

bool sortinrev1(const pair<int,int>&a,const pair<int,int>&b)
{
    //return (a.first > b.first);
    if(a.first==b.first)return (a.second>b.second);
    else return (a.first > b.first);
}
bool sortinrev2(const pair<int,int>&a,const pair<int,int>&b)
{
    //return (a.first > b.first);
    if(a.first==b.first)return (a.second<b.second);
    else return (a.first > b.first);
}
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};


int main()
{
    int n;
    cin>>n;
    if(n>=30)cout<<"Yes\n";
    else cout<<"No\n";
}

