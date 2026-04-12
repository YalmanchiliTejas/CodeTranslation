#include<bits/stdc++.h>

using namespace std;

#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n)　for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
#define Eunique(v) v.erace(unique(all(v)),v.end())
#define pvec(v)　rep(i,v.size()){cout << v[i] << " ";}
#define INF 0x3f3f3f3f
#define mset(m,v) memset(m,v,sezeof(m))
#define mod 1e9 +7;

const double pi = acos(-1.0);

typedef string ss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef deque<ll> dll;
typedef pair<ll,ll> P;
ll dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

ll gcd(ll x,ll y)
{
    ll r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

ll lcm(ll x,ll y)
{
    x /= gcd(x,y);
    y /= gcd(x,y);
    return (x*y);
}

int main()
{ 
    ll h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,h)cin >> s[i];

    rep(i,h){
        ll az=1;
        rep(j,w){
            ll counth=1,countw=1;
            rep(k,h-1){
                if(s[k][j] == s[k+1][j] && s[k][j] == '.')counth++;
            }
            rep(k,w-1){
                if(s[i][k] == s[i][k+1] && s[i][k] == '.')countw++;
            }

            if(counth != h && countw != w){
                cout << s[i][j];
                az=0;
            }
        }
        if(az == 0)cout << endl;
    }

    if(h == 1 && w == 1)cout << '#' << endl;
    return 0;
}