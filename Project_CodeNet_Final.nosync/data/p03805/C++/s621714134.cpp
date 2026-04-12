#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;
using namespace std;

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (int i = (a); i < (b); i++)
#define rrrep(i, a, b) for (int i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl

ll n, cnt, ans, a[ohara], b[ohara], c, d, tmp, tmpp, m, h, w, x, y, sum, pos, k;
ld doua;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
bool fl;
struct edge
{
    int to, cost;
};
vector<ll> g[ohara];
map<pair<ll,ll>,ll> mp;

//-------------------------↓↓↓↓↓↓------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    rep(i,m)cin>>a[i]>>b[i];
    rep(i,m){
        a[i]--;b[i]--;
        mp[{a[i],b[i]}]=1;
        mp[{b[i],a[i]}]=1;
    }
    vector<ll> p(n);
    rep(i,n)p[i]=i;
    do{
        if(p[0]!=0)continue;
        int ok=0;
        rep(i,n-1){
            if(mp[{p[i],p[i+1]}]==0)ok=1;
        }
        int kazo[n+10]={};
        rep(i,n)kazo[p[i]]++;
        rep(i,n){
            if(kazo[i]!=1)ok=1;
        }
        if(ok)continue;
        tmp=mp[{0,1}];
        ans++;
    }while(next_permutation(all(p)));
    Cout(ans);
    return 0;
}
