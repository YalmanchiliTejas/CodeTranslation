#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>

#include<stack>
#include<bitset>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include<unordered_map>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define aut(r,v) for(auto r:v)

#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define pc()  pop_back()

#define ull unsigned long long
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))

#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
#define endl '\n'

#define st stack<int>



#define vl vector<long long>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vs vector<string>

#define mod 1000000007

#define un  unordered_map<int,int>
#define mii map<int,int>

#define Sort(a) sort(all(a))
#define ED(a) Sort(a), a.erase(unique(all(a)), a.end())//removing all duplicates

#define max3(a, b, c)   max(a, max(b, c))
#define min3(a, b, c)   min(a, min(b, c))
#define Max(a)       *max_element(all(a))
#define Min(a)       *min_element(all(a))
#define MaxP(a)       max_element(all(a)) - a.begin()
#define MinP(a)        min_element(all(a)) - a.begin()

#define allUpper(a)     transform(all(a), a.begin(), :: toupper)
#define allLower(a)     transform(all(a), a.begin(), :: tolower)

#define rev(a)          reverse(all(a))
#define ub(v,k)          upper_bound(all(v), k) - v.begin()
#define lb(v,k)          lower_bound(all(v), k) - v.begin()
#define adv(a,n)        advance(auto it:a,n)
#define RSort(a)         sort(a.rbegin(),a.rend()) //decending order
#define cnt(v,a)             count(all(v),a)
#define bs(v,a)           binary_search(all(v),a)
#define mmax(v)           *max_element(all(v))
#define mmin(v)           *min_element(all(v))
#define popcount(mask)                       __builtin_popcount(mask) // count set bit
#define popcountLL(mask)                     __builtin_popcountll(mask) // for long long
#define X real() // useful for working with #include <complex> for computational geometry
#define Y imag()
#define ll long long
#define ss second
#define ff first

#define trace1(x)                           cerr << #x << ": " << x << endl;
#define trace2(x, y)                        cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                     cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)                  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)               cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)            cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

template <typename T> T gcd(T a, T b) { while (b) b ^= a ^= b ^= a %= b; return a; }
template <typename T> T setbit(T mask, T pos) { return mask |= (1 << pos); }
template <typename T> T resetbit(T mask, T pos) { return mask &= ~(1 << pos); }
template <typename T> T togglebit(T mask, T pos) { return mask ^= (1 << pos); }
template <typename T> T checkbit(T mask, T pos) { return (bool)(mask & (1 << pos)); }
template <typename T> T lcm(T a, T b) { return (a / gcd(a, b)) * b; }



template <typename T> T modu(T a, T b) { return (a < b ? a : a % b); }
template<typename T> T mod_neg(T a, T b) { a = mod(a, b); if (a < 0) { a += b; } return a; }

template <typename T>T expo(T e, T n) { T x = 1, p = e; while (n) { if (n & 1)x = x * p; p = p * p; n >>= 1; } return x; }
template<typename T> T mod_inverse(T a, T n) { T x, y; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : mod_neg(x, n)); }

template <typename T>T power(T e, T n, T m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x * p, m); p = mod(p * p, m); n >>= 1; } return x; }
template <typename T>T powerL(T e, T n, T m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; } return x; }

bool Pow2(int n) {
    return n && (!(n & (n - 1)));
}
void printc(vc& result) {
    aut(r, result) cout << r;
    cout << endl;
}
void printl(vl& result) {
    aut(r, result) cout << r << " ";
    cout << endl;
}
void print(vi& result) {
    aut(r, result) cout << r << " ";
    cout << endl;
}
// Recursively computes the power
int binpow(int a, int b)
{
    if (b == 0)
        return a;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
// iteratively computes the power
ll pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll modpow(ll a, ll b, ll m)
{
    a = a % m;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans % m * a % m) % m;
        b /= 2;
        a = (a % m * a % m) % m;
    }
    return ans;
}

ll ncr(ll n, ll k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k) 
    if (k > n - k)
        k = n - k;

    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < k; ++i) {
        res = res * (n - i);
        res /= (i + 1);
    }

    return res;
}
//ifstream cin("b_read_on.txt"); ofstream cout("output3.txt");
//Use (<<) for multiplication
//Use (>>) for division
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed;cerr.tie(NULL);
// find_by_order -> value at index
// order_of_key -> index of value
// while using (1<<i) use ((ll)1<<(ll)i) 
// in Floyd-Warshall Algo, k is outer loop 
// If an element was not initially in map and if asked mp[a],the element gets inserted 
// a%=mod take a lot of time... try to use it minimum and use memset as it reduces a lot of time usage...use if(a>=mod) a%=mod
//cout<<(double) can be harmful , always use printf(%.9llf)...take scanf("%lf",&p[i][j]) as input , not llf;
//use s.erase(it++) for erasing iterator and then moving to the next one
//never use adj.resize(n) as value is persistent, always erase
//use __builtin_popcountll() for ll
// no of prime numbers in range : (70,19) , (1000,168) , (100000,1229) , (sqrt(10^9),3409) ;
//always check the use of segment tree using bottom-up dp
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 }; // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction


int find(int a, vi& par) {
    if (par[a] == a) return a;
    return par[a] = find(par[a], par);
}
void merge(int a, int b, vi& par, int& count, vi& size) {
    a = find(a, par);
    b = find(b, par);

    if (a == b) return;
    count++;
    if (size[a] > size[b]) {
        size[a] += size[b];
        par[b] = a;
    }
    else {
        size[b] += size[a];
        par[a] = b;
    }



}




/*
void build(ll si, ll ss, ll se) {
    if (ss == se) {
        b[si] = arr[ss];
        return;
    }
    ll mid = ss + (se - ss) / 2;

    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    b[si] = (b[2 * si] + b[2 * si + 1]);

}
ll query2(ll si, ll ss, ll se, ll p, ll q) {
    if (ss > q || se < p) return 0;
    if (ss >= p && se <= q) {
        return b[si];

    }
    ll mid = ss + (se - ss) / 2;
    ll l = query2(2 * si, ss, mid, p, q);
    ll r = query2(2 * si + 1, mid + 1, se, p, q);
    return (l + r);



}
void update(ll si, ll ss, ll se, ll p, ll n) {
    if (ss == se) {
        arr[ss] = n;


        b[si] = arr[ss];
        return;
    }
    ll mid = se + ss;
    mid /= 2;
    if (p <= mid) update(2 * si, ss, mid, p, n);
    else update(2 * si + 1, mid + 1, se, p, n);
    b[si] = b[2 * si] + b[2 * si + 1];

}
bool used[6000];
bool vis[6000];
*/
//bool used[6000];
vector<int>v[100005];
int n;
long double p[100005];
int in[100005];
int vis[100005];
int dis[100005];
void bfs(int source) {
    vis[source] = 1;
    dis[source] = 0;
    queue<int>q;
    p[source] = 1.0;
    q.push(source);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto it : v[cur]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
                dis[it] = dis[cur] + 1;
                if (it == 1) p[it] = p[cur]/v[cur].size();
                else p[it] = p[cur] / (v[cur].size() - 1);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    test = 1;
    //cin >> test;
    //preprocess();

    while (test--) {
        int n;
        cin >> n;
        if (n >= 30)cout << "Yes" << endl;
        else cout << "No" << endl;
          
        
    }




};