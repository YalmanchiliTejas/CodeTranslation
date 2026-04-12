#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo, lo> ll; //pair
typedef vector<lo> vl;   //vector of long
typedef vector<ll> vll;  //vector of pair
typedef priority_queue<lo> p_q;
typedef vector<vl> vvl; //vector of vectors
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))
#define REP(a, b) for (lo i = (a); i < (lo)b; i++) //no need to declare variable i
#define REPE(a, b, c, d) REP(a, b) \
for (lo j = (c); j < (lo)d; j++)                        //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 500010
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)
#define _DEBUG 1
#if _DEBUG
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl;
#define debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define debug4(x, y, z, w) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define debug5(x, y, z, w, t)      \
    cout << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug6(p, x, y, z, w, t)                            \
    cout << #p << " " << p << " " << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug7(o, p, x, y, z, w, t) \
    cout << #o << " " << o << " ";  \
    debug6(p, x, y, z, w, t);
#define wait  \
    int xxxx; \
    cin >> xxxx;
#define derr(x) cerr << #x << "=" << x << endl;
#define derr2(x, y) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define derr3(x, y, z) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define derr4(x, y, z, w) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define derr5(x, y, z, w, t)       \
    cerr << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr6(p, x, y, z, w, t)                             \
    cerr << #p << " " << p << " " << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr7(o, p, x, y, z, w, t) \
    cerr << #o << " " << o << " "; \
    derr6(p, x, y, z, w, t);
lo checkpoint_counter=0;
#define checkpoint cerr << "At checkpoint : " << checkpoint_counter++ << endl;

#else
#define debug(x) ;
#define debug2(x, y) ;
#define debug3(x, y, z) ;
#define debug4(x, y, z, q) ;
#define debug5(x, y, z, r, t) ;
#define debug6(x, y, z, r, t, s) ;
#define debug7(x, y, z, r, t, s, u) ;
#define wait ;
#define derr(x) ;
#define derr2(x, y) ;
#define derr3(x, y, z) ;
#define derr4(x, y, z, q) ;
#define derr5(x, y, z, r, t) ;
#define derr6(x, y, z, r, t, s) ;
#define derr7(x, y, z, r, t, f, u) ;
#define checkpoint ;
#endif

#define print_matrix(a, n, m) \
    REPE(0, n, 0, m) { cout << (a)[i][j] << ((j == m - 1) ? '\n' : ' '); }
#define present(container, element) (container.find(element) != container.end())
#define endl "\n"
#define add(a) accumulate(all(a), lo(0));
#define add(a, x) accumulate(all(a), x);
template <typename T>
ostream &operator<<(ostream &o, vector<T> v)
{
    if (v.size() > 0)
        o << v[0];
    for (unsigned i = 1; i < v.size(); i++)
        o << " " << v[i];
    return o << " ";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p)
{
    return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (unsigned i = 0; i < v.size(); i++)
        in >> v[i];
    return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p)
{
    in >> p.X;
    in >> p.Y;
    return in;
}
template <typename T>
ostream &operator<<(ostream &o, set<T> v)
{
    TRV(v)
        o << it << " ";
    return o << endl;
}
template <typename T, typename U>
ostream &operator<<(ostream &o, map<T, U> v)
{
    TRV(v)
        o << it << " ";
    return o << endl;
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


lo tree[1000100]={0};

void build(lo node, lo start, lo end)
{
    if(start == end)
    {
        tree[node] = 0;
    }
    else
    {
        lo mid = (start + end) / 2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }
}

void update(lo node, lo start, lo end, lo idx, lo val)
{
    if(start == end)
    {
        // Leaf node
        //cout<<start<<" "<<end<<" "<<tree[node]<<endl;
        tree[node] = val;
    }
    else
    {
        lo mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node+1, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+2, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
        //cout<<start<<" "<<end<<" "<<tree[node]<<endl;
    }
}

lo query(lo node, lo start, lo end, lo l, lo r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    
    if(l <= start and end <= r)
    {
        //cout<<start<<" "<<end<<" "<<tree[node]<<endl;
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    lo mid = (start + end) / 2;
    lo p1 = query(2*node+1, start, mid, l, r);
    lo p2 = query(2*node+2, mid+1, end, l, r);
    return min(p1, p2);
}

bool cmp(ll a, ll b){
        if(a.X == b.X)return a.Y < b.Y;
        return a.X < b.X;
    }

lo vis[3000][3000][2];

ll traverse(lo x, lo y, vl& ve){
    if(x==y){
        vis[x][y][0]=ve[x];
        vis[x][y][1]=0;
        return mp(vis[x][y][0],vis[x][y][1]);
    }
    if(vis[x][y][0]!=LLONG_MIN)return mp(vis[x][y][0],vis[x][y][1]);
    
    ll l = traverse(x+1,y,ve);
    ll r = traverse(x,y-1,ve);
    if(ve[x]+l.Y == ve[y]+r.Y){
        if(r.X <= l.X){
            vis[x][y][0]=ve[y]+r.Y;
            vis[x][y][1]=r.X;
        }else{
            vis[x][y][0]=ve[x]+l.Y;
            vis[x][y][1]=l.X;
        }
    }else if(ve[x]+l.Y > ve[y]+r.Y){
        vis[x][y][0]=ve[x]+l.Y;
        vis[x][y][1]=l.X;
    }else{
        vis[x][y][0]=ve[y]+r.Y;
        vis[x][y][1]=r.X;
    }
    return mp(vis[x][y][0],vis[x][y][1]);
}

int main(){
    lo t;
    //cin>>t;
    t=1;
    while(t--){
        lo n,te,j;
        vl ve;
        cin>>n;
        REP(0,n){
            cin>>te;
            ve.pb(te);
        }
        REP(0,n){
            REPV(j,0,n){
                vis[i][j][0]=LLONG_MIN;
                vis[i][j][1]=LLONG_MIN;
            }
        }
        auto pa = traverse(0,n-1,ve);
        cout<<pa.X-pa.Y;
    }
    return 0;
}