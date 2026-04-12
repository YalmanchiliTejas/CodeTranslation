#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


#define mx 10000005



main(){
//read;

ll n,x,m;
cin>>n>>x>>m;


bool fl = 0;
int cnt = 0;
ll j = 0;

vector<ll> v = {x};
set<ll>st;
st.insert(x);

for(ll i = 2;  ; i++){
    ll p = le(v);
    p = (p*p)%m;
    v.pb(p);
    if(st.count(p)) break;
    st.insert(p);
}

ll p = le(v);
ll id,sum = 0;

for(ll i = 0; i<v.size() ; i++)
    if(v[i]==p) {
        id = i;
        for(ll j = i+1; j<v.size(); j++)
            sum+=v[j];
        break;
    }

ll len = v.size() - id - 1;

ll ans = 0;


if(n<=(int)v.size()){
    ll w = 0;
    for(ll i = 0; i<n; i++) w+=v[i];
    cout<<w;
    return 0;
}
v.pop_back();

ll w = 0;

for(ll j:v) w+=j;

p = (n-(ll)v.size())/len;
n = n - (p*len + v.size());
p*=sum;

w+=p;



for(ll j = 0; j<n   ; j++)
    w+=v[j+id];

cout<<w;


return 0;
}

