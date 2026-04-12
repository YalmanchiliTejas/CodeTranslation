
///"--------------------Bismillahir Rahmanir Rahim"-----------------------///

#include<bits/stdc++.h>
using namespace std;

///_____________________________FAST I/O__________________________________///
#define Boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///-----------------------------------------------------------------------///

///_____________________________DATA TYPE_________________________________///
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;
///-----------------------------------------------------------------------///

///_______________________________LOOP____________________________________///
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
///-----------------------------------------------------------------------///

///_________________________________I/O___________________________________///
#define sf scanf
#define pf printf
///-----------------------------------------------------------------------///

///_________________________________OTHERS________________________________///
#define pb push_back
#define all(c)		c.begin(),c.end()
#define MK make_pair
#define F first
#define S second
#define endl '\n'
///-----------------------------------------------------------------------///

///____________________________INITIALIZATION_____________________________///
#define mem(a,b) memset(a, b, sizeof(a) )
///-----------------------------------------------------------------------///

///____________________________CALCULATE__________________________________///
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))
///-----------------------------------------------------------------------///

///_____________________________BIT OPERATION____________________________///
inline bool checkBit(ll n, int i)
{
    return n&(1LL<<i);
}
inline ll setBit(ll n, int i)
{
    return n|(1LL<<i);;
}
inline ll resetBit(ll n, int i)
{
    return n&(~(1LL<<i));
}
///-----------------------------------------------------------------------///

///________________________String/Char Related Functions__________________///
string makeintString(int x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    ///cout<<str<<endl;
    return str;
}
string makellString(ll x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    ///cout<<str<<endl;
    return str;
}
char cpp(char c)
{
    return static_cast<char>(c + 1);
}
///-----------------------------------------------------------------------///

///__________________________Sorting STL_________________________________///
struct func
{
    //this is a sample overloading function for sorting stl
    bool operator()(pii const &a, pii const &b)
    {
        if(a.F==b.F)
            return (a.S<b.S);
        return (a.F<b.F);
    }
};
///-----------------------------------------------------------------------///

///____________________________CONSTANT___________________________________///
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
///-----------------------------------------------------------------------///

void solve()
{
    int x;
    cin>>x;
    if(x>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main()
{
    Boost();
    int t;
    t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
