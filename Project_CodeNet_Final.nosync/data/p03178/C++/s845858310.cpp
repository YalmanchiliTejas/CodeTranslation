#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

template<const ll mod>
struct modint
{
    ll val;
    
    inline ll normalize(ll n)
    {
        if(n >= mod || n < -mod)
            n %= mod;
        if(n < 0)
            n += mod;
        return n;
    }

    modint(){ val = 0;}
    template<class T> modint(T x = 0) { val = normalize(x);}
    template<class T> explicit operator T() { return static_cast<T>(val);}

    modint<mod>& operator += (const modint<mod> o) { return *this = modint<mod>(val + o.val);}   
    template<class T> modint<mod>& operator += (const T o) { return *this = modint<mod>(val + normalize(o));}   
    modint<mod>& operator -= (const modint<mod> o) { return *this = modint<mod>(val - o.val);}   
    template<class T> modint<mod>& operator -= (const T o) { return *this = modint<mod>(val - normalize(o));}   
    modint<mod>& operator *= (const modint<mod> o) { return *this = modint<mod>(val * o.val);}   
    template<class T> modint<mod>& operator *= (const T o) { return *this = modint<mod>(val * normalize(o));}

    modint<mod>& operator++() { return *this += 1;}
    modint<mod>& operator--() { return *this -= 1;}

    modint<mod> operator + (const modint<mod> o) { return modint<mod>(val + o.val);}   
    template<class T> modint<mod> operator + (const T o) { return modint<mod>(val + o);}   
    modint<mod> operator - (const modint<mod> o) { return modint<mod>(val - o.val);}   
    template<class T> modint<mod> operator - (const T o) { return modint<mod>(val - o);}   
    modint<mod> operator * (const modint<mod> o) { return modint<mod>(val * o.val);}   
    template<class T> modint<mod> operator * (const T o) { return modint<mod>(val * o);}

    bool operator == (const modint<mod> o) { return val == o.val;}
    template<class T> bool operator == (const T o) { return val == normalize(o);}
    bool operator != (const modint<mod> o) { return val != o.val; }
    template<class T> bool operator != (const T o) { return val != normalize(o);}

    bool operator < (const modint<mod> o) { return val < o.val;}
    template<class T> bool operator < (const T o) { return val < normalize(o);}

    modint<mod>& operator /= (const modint<mod> o) { return *this *= o.inv();}
    template<class T> modint<mod>& operator /= (const T o) { return *this *= modint<mod>(o).inv();}
    modint<mod> operator / (modint<mod> o) {modint<mod> ans(val); return ans * o.inv();}
    template<class T> modint<mod> operator / (T o) { return modint<mod>(val) / modint<mod>(o);}

    modint<mod> inv() { return fexp(*this, mod - 2);}

    friend istream& operator >> (istream& in, modint<mod>& n)
    {
        ll x; in >> x;
        n = modint<mod>(x);
        return in;
    }

    friend ostream& operator << (ostream& out, const modint<mod>& n)
    {
        return out << n.val;
    }
};

const int N = 1e4 + 10, D = 110;
modint<MOD> dp[N][D][2];
bool vis[N][D][2];
string s;
int m;

modint<MOD> solve(int i, int j, bool k)
{
    if(i == LEN(s))
        return j == 0;
    
    modint<MOD>& ans = dp[i][j][k];

    if(!vis[i][j][k])
    {
        if(k)
        {
            for(int z = 0; z <= 9; z++)
                ans += solve(i + 1, (j + z) % m, k);
        }
        else
        {
            int c = s[i] - '0';
            for(int z = 0; z <= c; z++)
                ans += solve(i + 1, (j + z) % m, z < c);
        }

        vis[i][j][k] = true;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    cin >> s >> m;

    cout << solve(0, 0, 0) - 1 << endl;
    
    return 0;
}