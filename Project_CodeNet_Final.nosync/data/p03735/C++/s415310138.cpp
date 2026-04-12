/// a.cpp

# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
const pair < int , int > DD[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
# define fi cin
# define fo cout
# define x first
# define y second
# define ll long long
# define IOS ios_base :: sync_with_stdio(0);cin.tie(0)
# define p(v) cerr << #v << " = " << v << '\n'
# define p2(v) cerr << #v << " = " << (complex < __typeof(v.x) > (v.x,v.y)) << '\n'
# define vi vector < int >
# define vl vector < ll >
# define pll pair < ll , ll >
# define pii pair < int , int >
# define mp make_pair
# define db long double
# define fail puts("-1")
# define yes puts("YES")
# define no puts("NO")
# define PP puts("Possible")
# define II puts("Impossible")
# define vii vector < pii >
# define vll vector < pll >
# define pb push_back
# define pdd pair < db , db >
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
int main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    int Rmin = 2e9,Rmax = 0,Bmin = 2e9,Bmax = 0;
    int n;
    fi>>n;
    priority_queue < pii , vii , greater < pii > > q;
    multiset < int > s1,s2;
    while (n --)
    {
        int a,b;
        fi>>a>>b;
        if (a > b) swap(a,b);
        smin(Rmin,a);
        smin(Bmin,b);
        smax(Rmax,a);
        smax(Bmax,b);
        q.push(mp(a,b));
        s1.insert(a);
        s2.insert(b);
    }
    ll ans = 1ll * (Bmax - Bmin) * (Rmax - Rmin);
    while (!q.empty())
    {
        auto node = q.top();
        q.pop();
        s1.erase(s1.find(node.x));
        s1.insert(node.y);
        s2.erase(s2.find(node.y));
        s2.insert(node.x);
        smin(ans,1ll * (*s1.rbegin() - *s1.begin()) * (*s2.rbegin() - *s2.begin()));
        if (node.x >= node.y)
            break;
        q.push(mp(node.y,node.x));
    }
    fo << ans << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}
