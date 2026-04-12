#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double EPS = 1e-7;
const long long mod = 1000000007 ;
const int N = 1000000;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define HelloFile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ll long long
#define ld long double
#define X real()
#define Y imag()
#define cross(a,b) (conj(a)*(b)).imag()
#define dot(a,b) (conj(a)*(b)).real()
#define dist(a,b) ( pow(a.X - b.X, 2) + pow( a.Y - b.Y, 2 ) )
typedef tuple <int, int, int> line;
typedef complex <double> point;
typedef vector <point> polygon;
ll n, rep[N], sz[N], cost = 0;
vector< pair<ll, pair<ll, ll> > > vx, vy;
map< ll, vector< pair<ll, ll> > > mp;
int findU(int u)
{
    return ( rep[u] == u )? u : rep[u] = findU(rep[u]);
}
bool join(int a, int b)
{
    a = findU(rep[a]);
    b = findU(rep[b]);
    if( a == b )
        return true;
    if( sz[a] < sz[b] )
        swap(a, b);
    sz[a] += sz[b];
    rep[b] = a;
    return false;
}
int main()
{
    Hello
    for(int i = 0; i <= 100005; i++)
        rep[i] = i;
    for(int i = 0; i <= 100005; i++)
        sz[i] = 1;
    cin >> n;
    for(int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        vx.push_back( {x, {y, i}} );
        vy.push_back( {y, {x, i}} );
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    for(int i = 0; i < vx.size() - 1; i++)
    {
        mp[ abs( vx[i].first - vx[i + 1].first ) ].push_back( {vx[i].second.second, vx[i + 1].second.second} );
        mp[ abs( vy[i].first - vy[i + 1].first ) ].push_back( {vy[i].second.second, vy[i + 1].second.second} );
    }
    map< ll, vector< pair<ll, ll> > > :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        for(ll j = 0; j < (it->second).size(); j++)
        {
            if ( !join( (it->second)[j].first, (it->second)[j].second ) )
                cost += (it->first);
        }
    }
    cout << cost;
    return 0;
}
