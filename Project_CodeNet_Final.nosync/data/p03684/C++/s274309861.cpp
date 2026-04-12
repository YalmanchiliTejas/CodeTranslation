#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define T() int tt; cin>>tt; while(tt--)
#define mp make_pair
#define pb push_back
#define lchild (2*node+1)
#define rchild (2*node+2)
#define f first
#define s second
#define br cout<<endl
#define MOD (1000000007LL)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b){
    if(b==0)return a;
    else gcd(b, a%b);
}

ull pwr(ull base, ull p, ull mod=MOD){
    ull ans = 1;
    while(p){
        if(p&1)ans=((ans%mod) * (base%mod))%mod;
        base=((base%mod) * (base%mod))%mod;
        p/=2;
    }
    return ans;
}

const int N = (int) 1e6+500;
int n;
int root[N];

void build(){
    for(int i=0; i<n; ++i){
        root[i]=i;
    }
}
int get_root(int a){
    if(root[a]!=a){
        root[a]=get_root(root[a]);
    }
    return root[a];
}

bool un(int a, int b){
    a = get_root(a);
    b = get_root(b);
    if(a==b){
        return false;
    }
    else{
        root[a] = b;
        return true;
    }
}

vector<pair<ll, int> >vx,vy;
vector<tuple<ll, int, int> > edge;

int main(){
    FIO
    cin >> n;
    build();
    for(int i=0; i<n; ++i){
        ll x,y;
        cin >> x >> y;
        vx.pb(mp(x,i));
        vy.pb(mp(y,i));
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    for(int i=0; i<vx.size()-1; ++i){
        ll cost = abs(vx[i].f - vx[i+1].f);
        edge.pb(make_tuple(cost, vx[i].s, vx[i+1].s));
    }
    for(int i=0; i<vy.size()-1; ++i){
        ll cost = abs(vy[i].f - vy[i+1].f);
        edge.pb(make_tuple(cost, vy[i].s, vy[i+1].s));
    }
    ll res = 0;
    sort(edge.begin(), edge.end());

    for(int i=0; i<edge.size(); ++i){
        ll d; int u,v;
        tie(d,u,v) = edge[i];
        if(un(u,v)){
            res += d;
        }
    }

    cout << res << endl;

return 0;
}
