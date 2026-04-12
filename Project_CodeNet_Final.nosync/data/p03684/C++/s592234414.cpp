#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ll n;
ll xx[100005] , yy[100005];
ll p[200005];
ll fs(ll x)
{
        return p[x] == x ? x : p[x] = fs(p[x]);
}
void us(ll a , ll b)
{
        a = fs(a);
        b = fs(b);
        p[b] = a;
}
class pt1
{
public:
        ll x , y , id;
        pt1()
        {

        }
        pt1(ll a , ll b, ll yo)
        {
                x = a;
                y = b;
                id = yo;
        }
        bool operator< (pt1 &ot)
        {
                return x < ot.x;
        }
};
class pt2
{
public:
        ll x , y , id;
        pt2()
        {

        }
        pt2(ll a , ll b, ll yo)
        {
                x = a;
                y = b;
                id = yo;
        }
        bool operator< (pt2 &ot)
        {
                return y < ot.y;
        }
};
class edge
{
public:
        ll w , from , to;
        edge(ll a , ll b , ll c)
        {
                from = a;
                to = b;
                w = c;
        }
        bool operator< (edge &ot)
        {
                return w < ot.w;
        }
};
vector<pt1> A;
vector<pt2> B;
vector< pair<ll,ll> > g[500005];
vector< edge > e;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n;
        for(ll i=1;i<=n;i++)
        {
                ll p , q;
                cin >> p >> q;
                xx[i] = p;
                yy[i] = q;
                pt1 aa(p , q ,i);
                pt2 bb(p , q ,i);
                A.pb(aa);
                B.pb(bb);
        }
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());
        for(ll i = 1 ;i < A.size() ; i++)
        {
                ll X = A[i].id;
                ll Y = A[i-1].id;
                ll ww = min(abs(xx[X] - xx[Y]) , abs(yy[X] - yy[Y]));
                edge E(X , Y , ww);
                e.pb(E);
        }
        for(ll i=1;i<B.size();i++)
        {
                ll X = B[i].id;
                ll Y = B[i-1].id;
                ll ww = min(abs(xx[X] - xx[Y]) , abs(yy[X] - yy[Y]));
                edge E(X , Y , ww);
                e.pb(E);
        }
        sort(e.begin() , e.end());
        for(ll i = 1 ; i <= n ; i++) p[i] = i;
        ll ans = 0;
        for(auto i : e)
        {
                //cout << i.from << " " << i.to << " " << i.w << endl;
                if(fs(i.from) == fs(i.to)) continue;
                us(i.from , i.to);
                ans += i.w;
        }
        cout << ans << endl;
        return 0;
}
