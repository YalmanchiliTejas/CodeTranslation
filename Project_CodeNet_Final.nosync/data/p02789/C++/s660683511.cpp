#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define REVE(x) reverse((x).begin(),(x).end())
#define mp make_pair
#define pb push_back
#define chmax(x,y) x = max(x,y)

 
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<bool> VB;
typedef vector<LL> VL;
typedef vector<vector<long long>> VVLL;
typedef vector<set<int>> VSI;
const int MOD = 1e9+7;
const int INF = 1e9;
const LL LINF = 1e18;
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}
struct UnionFind {
    VI d;
    UnionFind(int n = 0): d(n,-1) {}
    int find(int x) {
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x,int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x,int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};
int deg[100005];
VI to[100005];

struct mint {
  LL x; // typedef long long ll;
  mint(LL x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(LL t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

mint f(int n) {
    if(n == 0) return 1;
    mint x = f(n/2);
    x *= x;
    if(n%2 == 1) x *= 2;
    return x;
}

mint choose(int n,int a) {
    mint x = 1, y = 1;
    rep(i,a) {
        x *= n-i;
        y *= i+1;
    }
    return x/y;
}

int main() {
    int n,m;
    cin >> n >> m;
    if(n==m) cout << "Yes" << endl;
    else cout << "No" << endl;
}
