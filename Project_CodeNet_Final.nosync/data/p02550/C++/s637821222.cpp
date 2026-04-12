#include <bits/stdc++.h>
typedef long long       ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define mt                make_tuple
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define forr(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define deb(x)			  cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x)             (int)x.size()
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int INF = 1234567890;

const int tam = 1e5 + 10;

bool vis[tam];

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ll n, x, m;
    cin >> n >> x >> m;
    if (n <= m) {
        ll res = 0;
        fore(i, 0, n) {
            res += x;
            x = x * x % m;
        }
        cout << res << '\n';
        return 0;
    }
    ll cycleSum = 0, cycleLen = 0;
    ll actX = x;
    //cout << "cola -> ciclo" << endl;
    while (vis[actX] == false) {
        //cout << actX << " -> ";
        vis[actX] = true;
        cycleLen++;
        cycleSum += actX;
        actX = actX * actX % m;
        //cout << actX << endl;
    } 
    ll tail = cycleSum;
    ll tailLen = cycleLen;
    cycleSum = 0;
    cycleLen = 0;
    //cout << "ciclo" << endl;
    while (vis[actX] == true) {
        //cout << actX << " -> ";
        vis[actX] = false;
        cycleLen++;
        cycleSum += actX;
        actX = actX * actX % m;
        //cout << actX << endl;
    }
    tail -= cycleSum;
    tailLen -= cycleLen;
    ll res = tail;
    n -= tailLen;
    ll completeCycles = n/cycleLen;
    ll diff = n - completeCycles*cycleLen;
    res += completeCycles * cycleSum;
    x = actX;
    fore(i, 0, diff) {
        res += x;
        x = x*x % m;
    }
    cout << res << '\n';
    return 0;
}
// Dinosaurs are cool!