/// --- In the name of ALLAH --- ///


#include <cmath>
#include<bits/stdc++.h>
using namespace std;


typedef long long              ll;
typedef vector<int>            vi;
typedef vector<ll>             vl;
typedef vector<vi>             vvi;
typedef vector<vl>             vvl;
typedef pair<int,int>          pii;
typedef pair<double, double>   pdd;
typedef pair<ll, ll>           pll;
typedef vector<pii>            vii;
typedef vector<pll>            vll;
typedef double                 dl;

#define endl                   '\n'
#define PB                     push_back
#define F                      first
#define S                      second
#define all(a)                 (a).begin(),(a).end()
#define rall(a)                (a).rbegin(),(a).rend()
#define sz(x)                  (ll)x.size()
#define wt                     ll t; cin>>t; while(t--)
#define input(a,n)             for(int i=0;i<n;i++) cin>>a[i];

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;


#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
#define mod 10000007
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


const ll mx=1e9;



//q=51;

//ll b[q+1][q+1];


 main()
{
    optimize();
    int h,w,i,j;
    cin>>h>>w;
    vi v1,v2;
    char a[h+1][w+1],b[h+1][w+1];
    set<char>r[h+1],c[w+1];
    for(i=1;i<=h;i++)
    {
       for(j=1;j<=w;j++){
            cin>>a[i][j];
            r[i].insert(a[i][j]);
            }
    }
    for(auto u=1;u<=h;u++)
    {
        if(sz(r[u])==1)
        {
            for(auto q:r[u])
            {
                if(q=='.')
                    v1.PB(u);

            }
        }
    }
    /*for(auto u:v1)
        cout<<u;*/

for(j=1;j<=w;j++)
    {
       for(i=1;i<=h;i++){
            //cin>>a[i][j];
            c[j].insert(a[i][j]);
            }
    }
    for(auto u=1;u<=w;u++)
    {
        if(sz(c[u])==1)
        {
            for(auto q:c[u])
            {
                if(q=='.')
                    v2.PB(u);

            }
        }
    }
     for(i=1;i<=h;i++)
    {
        int p=0;
        for(auto u:v1)
            {
                if(i==u){
                    p++;
                    break;}
            }
            if(p==1)
                continue;
       for(j=1;j<=w;j++){
           int k=0;
            for(auto u:v2)
            {
                if(j==u){
                    k++;
                    break;}
            }
            if(k==1)
                continue;
            cout<<a[i][j];


       }
       cout<<endl;

    }




    return 0;
}




























































































