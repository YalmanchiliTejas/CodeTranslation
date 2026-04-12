#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=(a);i<=(int)(n);++i)
#define lpd(i,a,n) for(int i=(a);i>=(int)(n);--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define readll(x) scanf("%I64d",&x)
#define mod 1000000007
#define eps 1e-6
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

const int N = 100002;
int n,parent[N];
struct str {int f,s,i;} a[N];
vector<str> edges;

int find(int a) {return parent[a] == a ? a : parent[a] = find(parent[a]);}
void merge(int a, int b) {parent[find(a)] = parent[find(b)];}

int main(){
    readi(n);
    lp(i,1,n) read2i(a[i].f, a[i].s), a[i].i = parent[i] = i;

    sort(a+1, a+1+n, [](str x, str y){return x.f < y.f;});
    lp(i,1,n-1) edges.pb({a[i].i, a[i+1].i, a[i+1].f - a[i].f});
    sort(a+1, a+1+n, [](str x, str y){return x.s < y.s;});
    lp(i,1,n-1) edges.pb({a[i].i, a[i+1].i, a[i+1].s - a[i].s});

    sort(all(edges), [](str x, str y){return x.i < y.i;});

    ll ans = 0;
    for(str x : edges){
        if(find(x.f) != find(x.s)){
            ans += x.i;
            merge(x.f, x.s);
        }
    }
    cout <<ans;
}

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios::sync_with_stdio(0);cin.tie(0);
