//bad_bat
#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define MOD 1000000007

ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

int main()

{

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll mx = max(x,y);
    mx*=2;
    ll cst = inf;
    for(ll i = mx; i >= 0; i--)
    {

        ll abc = i*c;
        ll acab=i/2;
        ll an=0, bn=0;
        if(x > acab) an=x-acab;
        if(y > acab) bn = y-acab;
        ll tc = abc+an*a+bn*b;
        //cout << "CH " << i << " " << acab << " " <<
        cst = min(cst,tc);
    }
    cout << cst;
}
