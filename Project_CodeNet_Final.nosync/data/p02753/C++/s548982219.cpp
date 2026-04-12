#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for(int i=(l);i<(r);i++)
#define forb(i,r,l) for(int i=(r);i>(l);i--)
#define log2i(x) 32 - __builtin_clz((x)) - 1
#define log2ll(x) 64 - __builtin_clzll((x)) - 1
#define Pi acos(-1.0)
#define sz(x) (int)x.size()
#define pw(x,y) trunc(exp(log((x))*(y)))
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

string st;

int main() {
#ifndef ONLINE_JUDGE
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
#endif
    fastIO;
    cin >> st;
    if(count(all(st),'A')==2||count(all(st),'B')==2) cout << "Yes";
    else cout << "No";
    return 0;
}
