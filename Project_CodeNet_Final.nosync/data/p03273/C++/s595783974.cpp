#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define sz(c) int(c.size())
#define clr(v, d)   memset(v, d, sizeof(v))
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define INF             INT64_MAX
#define NINF            INT64_MIN

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<pll> vll;
typedef vector<ll> vl;

string neg2base(ll num)
{
    string res="";
    while(num!=0)
    {
        ll rem=num%(-2);
        num=num/(-2);
        if(rem<0)
        {
            num++;
            rem+=1;
        }
        res=to_string(rem)+res;

    }
    return res;
}
ll vis_row[101];
ll vis_col[101];
int main()
{
    //    std::ios_base::sync_with_stdio(false);
    //    cin.tie(NULL);
    //    cout.tie(NULL);

    //    freopen("popcorn.in", "r", stdin);

    //    ll t;
    //    cin>>t;
    //    while(t--)
    //    {
    ll n,m;
    cin>>n>>m;
    vector<string> lines(n);
    for(int i=0;i<n;i++)
        cin>>lines[i];

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            if(lines[i][j]!='.')
            {
                vis_col[j]=true;
                vis_row[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;(j<m)&&(vis_row[i]);j++)
        {
            if(vis_col[j])
                cout<<lines[i][j];
        }
        if(vis_row[i])
            cout<<endl;
    }
    return 0;
}
