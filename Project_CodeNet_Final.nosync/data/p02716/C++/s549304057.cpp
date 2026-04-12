#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ld,ld> id;

#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define ROF(i, a, b) for(int i=(a); i>=(b); i--)
#define MEM(x, v) memset(x, v, sizeof(x))
#define FILL(x, n, v) fill(x, x+n, v);
#define ALL(x) x.begin(), x.end()
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define f first
#define s second
#define ins insert
#define e emplace
#define eb emplace_back
#define ef emplace_front
#define p push
#define pf push_front
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define ft front
#define bk back
#define pp pop
#define ppb pop_back
#define ppf pop_front

#define db cout<<"YEET\n";
#define ct(x) cout<<x<<'\n';

const ll MOD = 1e9+7; //998244353
const ll MAXN = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);

ll st[MAXN], sz;

void update(ll x, ll val){
    x+=sz;
    st[x]=val;
    while (x){
        x/=2;
        st[x] = max(st[x<<1], st[x<<1|1]);
    }
    return;
}

ll query(ll a, ll b){
    a+=sz, b+=sz;
    ll res=0;
    for (; a<b; a>>=1, b>>=1){
        if (a&1) res = max(res, st[a++]);
        if (!(b&1)) res = max(res, st[b--]);
    }
    if (a==b) res = max(res, st[a]);
    return res;
}

int main(){
    FAST
    ll n;
    vector<ll> v;
    cin >> n;

    v.pb(0);
    FOR(i,1,n){
        ll x;
        cin >> x;
        v.pb(x);
    }

    if (n%2){
        ll ans=-INF;
        ll sum=0;
        for (int i=2; i<n; i+=2){
            sum += v[i];
        }

        ans = max(ans, sum);

        sz = n/2;
        ll left[sz+1], right[sz+1];

        for (int i=1; i<=sz; i++){
            left[i] = v[i*2-1] - v[i*2];
            right[i] = v[i*2+1] - v[i*2];
        }

        for (int i=sz; i; i--){
            if (i==sz) update(i-1, right[i]);
            else {
                right[i] += right[i+1];
                update(i-1, right[i]);
            }
        }

        left[0] = 0;
        ll change=0;
        for (int i=0; i<=sz; i++){
            change += left[i];
            ll maxx = query(i,sz-1);
            ll final = sum + change + maxx;
            ans = max(ans, final);
        }

        cout << ans;


    } else {
        ll ans=-INF;
        ll sum=0;
        for (int i=1; i<n; i+=2){
            sum += v[i];
        }
        ans = max(ans, sum);
        for (int i=n; i; i-=2){
            sum-=v[i-1];
            sum+=v[i];
            ans = max(ans, sum);
        }

        cout << ans;
    }
}