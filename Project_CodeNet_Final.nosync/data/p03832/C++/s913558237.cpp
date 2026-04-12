


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second

using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
//const int mod=998'244'353;
//const int mod=1e9+9;
//const int INF=4e18+10;
const int INF = 4e18 + 10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define read(n) \
int n;      \
cin >> n;
#define readv(x, n)   \
vector<int> x(n); \
for (auto &i : x) \
    cin >> i;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

template <typename T1, typename T2>
void set_min(T1 &a, T2 b)
{
    a = min(a, (T1)b);
}

int multiply(int a, int b, int in_mod) { return (int)(1LL*a * b % in_mod );}
int mult_identity(int a) { return 1; }

int mod_inv(int q, int in_mod);

// const int mod = 998244353;
const int root  = 15311432;
const int root_pw = 1<<23;
const int root_1 = mod_inv(root, mod);

//const int mod = 7340033;
//const int root  = 5;
//const int root_pw = 1<<20;
//const int root_1 = 4404020;

vector<int >multiply(const vector<int>& a, const vector<int>& b,int mod);
vector<int> mult_identity(vector<int> a)
{
    return {1};
}

vector<int> operator%(vector<int> a, int mod)
{
    return a;
}

auto power(auto a, int b, int in_mod)
{
    auto prod = mult_identity(a);
    auto mult = a % in_mod;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod - 2, in_mod);
}

const int MAXN = 1e6+100;
struct NODE
{
   int n4=0, n7=0, n47=0, n74=0;
   bool marked=false;
   void flip()
   {
       swap(n7, n4);
       swap(n74, n47);
   }
   NODE operator+(const NODE& other)
   {
       NODE n;
       n.n4 = this->n4 + other.n4;
       n.n7 = this->n7 + other.n7;
       n.n47 = max({this->n47+other.n7,this->n4+ other.n47,this->n4 + other.n47, this->n4 + other.n7 });
       n.n74 = max({this->n74+other.n4,this->n7+ other.n74,this->n7 + other.n74, this->n7 + other.n4 });
       return n;
   }
   NODE operator=(int x)
   {
       if(x == 4)
           this->n4 = 1;
       else
           this->n7 = 1;
       return *this;
   }


} t[MAXN*4];
void push(int v)
{
    if(t[v].marked){

       t[2*v].flip();
       t[2*v+1].flip();
       t[2*v].marked =!t[2*v].marked;
       t[2*v+1].marked =!t[2*v+1].marked;
       t[v].marked = !t[v].marked;

    }
}

void build(string &s, int node, int tl, int tr)
{
    int tm = (tl+tr)/2;
    if(tl == tr)
    {
        t[node] = s[tl] -'0';
        return;
    }
    build(s, 2*node, tl, tm);
    build(s, 2*node+1, tm+1, tr);
    t[node] = t[2*node] + t[2*node+1];
}
void update(int node, int tl, int tr, int l, int r )
{
    if(l>r)
        return ;
    int tm = (tl+tr)/2;
    if(l==tl && r == tr)
    {
        t[node].flip();
        t[node].marked =!t[node].marked;
        return;
    }
    push(node);
    update(2*node, tl, tm, l, min(tm, r));
    update(2*node+1, tm+1, tr, max(l, tm+1), r);

    t[node] = t[2*node] + t[2*node+1];

}

int query(int node)
{
    return max({t[node].n47, t[node].n4, t[node].n7});
}

const int MAXL = 22;
vector<int> table[MAXL];


#define norm(x) (x)>=mod? x-mod:x
#define norm_cheap(x) (x)<0? x+mod:x

void fft(vector<int> & a, bool invert, int lg) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {

        if (i < table[lg][i])
            swap(a[i], a[table[lg][i]]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u  - v >= 0 ? u - v : u - v +mod ;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = mod_inv(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}
vector<int >multiply(const vector<int> &a, const vector<int> &b, int mod)
{
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    int lg = 0;
    while(n<fa.size() + fb.size())
        n<<=1, lg++;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false, lg);
    fft(fb, false,lg);


    for(int i=0;i<n;i++)
        fa[i] = (int)(1LL*fa[i]*fb[i]%mod);
    fft(fa, true, lg);

    while(fa.size() && fa.back()== 0)
        fa.pop_back();
    return fa;
}

vector<int> fac(MAXN);
vector<int> infac(MAXN);
void build_factorial()
{
    fac[0]=1;
    infac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        infac[i]=mod_inv(fac[i], mod);
    }
}


int find(int d, int k, int i)
{
    int a= fac[d];
    a= (a* power(infac[i], k,mod))%mod;
    a = (a* infac[k])%mod;
    return a;
}
void solve()
{
    build_factorial();
    int n, a, b, c, d;
    cin>>n>>a>>b>>c>>d;
    int dp[b+1][n+1] = {};
    for(int i= 0;i<=b;i++)
        dp[i][0] = 1;
    for(int i= a;i<=b;i++)
    {
        for(int j= 0;j<=n;j++)
        {
        dp[i][j] = dp[i-1][j];

            for(int k= c;k<=d;k++)
            {
                int d = j - i*k;
                if(d>=0)
                {
                    dp[i][j] += (dp[i-1][d]*find(i*k,k, i)%mod*fac[j]%mod*infac[i*k]%mod*infac[j-i*k]%mod)%mod;
                    dp[i][j]%=mod;
                }
            }
        }
    }
    cout<<dp[b][n]<<endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
#ifndef ONLINE_JUDGE
    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    }
#endif
    auto clk = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // -------------------------------------Code starts here---------------------------------------------------------------------

    int t = 1;
    //cin >> t;

    for (int test = 1; test <= t; test++)
    {
        // cout<<"Case #"<<test<<":\n";
        //cout<<"Trip #"<<test<<": ";
        // cout<<endl;
        solve();
        // solveB();

        // cout<<endl;
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;
    // cerr << fixed << setprecision(6) << "Time: " << ((long double)clk) / CLOCKS_PER_SEC << "\n";
    return 0;
}
