#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define scontains(c, x) ((c).find(x) != (c).end())   //O(log n)
#define contains(c, x) (find((c).begin(),(c).end(),x) != (c).end()) //O(n)
#define ill(_x)  ll _x;scanf("%lld",&_x);
#define idb(_x)  double _x;scanf("%lf",&_x);
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vs vector<string>
#define in0(x, a, b)((x)>=a && (x)<=b    )
#define in1(x, a, b)((x)>a && (x)<b)
#define  rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define  _for(i, end) for (__typeof(end) i = 0; i < (end); i += 1)
#define all(x) (x).begin(),(x).end()
//#define len(array)  (sizeof(array)/sizeof((array)[0]))
#define endl '\n'
#define int ll

const double PI = 3.14159265358979323846;
const int INF = 0x3f3f3f3f;
const int LLINF = 1000000000000000005LL;;
const int MOD = (int) (1e9) + 7;
const int MX = 777777 + 5;
const int mod = 1777777777;
const double EPS = 1e-10;
const ll MXP = 8999251775770639633;
const int _500k = 500005;
const int _1m = 1000005;
const int _200k = 200005;
const int _20k = 20005;
const int _100k = 100005;
const int _10k = 10005;
int readint(){int x;cin >> x;return x;}

template <typename T>
ostream& operator << (ostream& os, const vector<T>& v){
    for(auto a : v)os << a << " ";
    return os;
}
template <typename T>
ostream& operator << (ostream& os, const set<T>& v){
    for(auto a : v)os << a << " ";
    return os;
}


inline int len(string s){return s.size();}
inline int len(int* A){return (sizeof(A))/sizeof(A[0]);}
template <typename T>inline int len(vector<T> v){return v.size();}
template <typename T>inline int len(set<T> v){return v.size();}
template <typename T,typename S>inline int len(map<T,S> v){return v.size();}

int fac[MX+5];
int power_mod(int x, int y, int p)
{
    if(y<0)return 0;
    int res = 1;

    x = x % p;

    while (y)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int power(int x, int y)
{
    if(y<0)return 0;
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x *=x ;
    }
    return res;
}


// Returns n^(-1) mod p
int modInverse(int n, int p)
{
    return power_mod(n, p-2, p);
}

int comb_mod(int n, int r, int p)
{
    if (r==0)
        return 1;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

void init(int mod){
    fac[0] = 1;
    for (int i=1 ; i<=MX; i++)
        fac[i] = fac[i-1]*i%mod;
}

int comb(int a, int b){
    int res = 1;
    rep(i,a+1,a-b+1)res *= i,res/=a-i+1;
//    rep(i,1,b+1)res /= i;
    return res;
}

bool equal(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

struct UnionFind
{
    // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
    vector<int> par;
    // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
    vector<int> sizes;

    UnionFind(int n) : par(n), sizes(n, 1) {
        // 最初は全てのデータiがグループiに存在するものとして初期化
        rep(i,0,n) par[i] = i;
    }

    // データxが属する木の根を得る
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
    }

    // 2つのデータx, yが属する木をマージする
    void unite(int x, int y) {
        // データの根ノードを得る
        x = find(x);
        y = find(y);

        // 既に同じ木に属しているならマージしない
        if (x == y) return;

        // xの木がyの木より大きくなるようにする
        if (sizes[x] < sizes[y]) swap(x, y);

        // xがyの親になるように連結する
        par[y] = x;
        sizes[x] += sizes[y];
        // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // データxが含まれる木の大きさを返す
    int size(int x) {
        return sizes[find(x)];
    }
};


//fastest
struct cpmFunctor{
    inline bool operator()(const pair<int,int> &p1, const pair<int,int> & p2){
        return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
    if(n==2 || n==3)return true;
    if(n%2==0 || n%3==0)return false;
    // Check from 2 to n-1
    for (int i = 5; i*i <= n; i+=6)
        if (n % i == 0)
            return false;
    for (int i = 7; i*i <= n; i+=6)
        if (n % i == 0)
            return false;

    return true;
}

int lcm(int a, int b){
    return a / __gcd(a,b) * b;
}

map<int, int> factorize(long long n)
{
    map<int, int> factors;
    int count = 0;

    while (!(n % 2)) {
        n >>= 1;
        count++;
    }

    if(count)factors[2] = count;

    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            factors[i] = count;
    }

    if (n > 2)
        factors[n] = 1;
    return factors;
}


class Graph{
    int V;
    vector<int>* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new vector<int>[V];

    }

    void addEdge(int from, int to){
        adj[from].push_back(to);
    }


    bool isCyclicUtil(int v, bool visited[], bool *recStack)
    {
        if(visited[v] == false)
        {
            // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;

            // Recur for all the vertices adjacent to this vertex
            for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                    return true;
                else if (recStack[*i])
                    return true;
            }

        }
        recStack[v] = false;  // remove the vertex from recursion stack
        return false;
    }

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
    bool isCyclic()
    {
        // Mark all the vertices as not visited and not part of recursion
        // stack
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }

        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for(int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;

        return false;
    }


};

struct edge{
    int to;
    int cost;
};

class wGraph{
    int V;
    vector<edge>* adj;

public:
    wGraph(int V){
        this->V = V;
        adj = new vector<edge>[V];
    }

    void addEdge(int from, int to, int cost){
        adj[from].push_back({to, cost});
    }
};

vector<int> V,VV;
string S[_100k];

bool over(int l, string s){
    if(l > s.size())return 1;
    return 0;
}

bool ok(int l){
    string sf = S[V[0]];
    if(over(l, sf))return 0;
    string s = sf.substr(0,l);
    for(auto i : V)if(over(l,S[i])||S[i].substr(0,l) != s)return 0;
    return 1;
}

bool okk(int l, string s){
    for(auto i : VV){
        if(over(l,S[i]))continue;
        if(S[i].substr(0,l) == s.substr(0,l))return 0;
    }
    return 1;
}

int n,x;
int L[55];
int P[55];
void _(){
    int n,x;
    cin >> n >> x;
    L[0] = P[0] = 1;
    _for(i,n)L[i+1] = 2*L[i]  + 3, P[i+1] = 2*P[i] + 1;
    int res = 0;
    while(x && n){
        if(x >= 2 + L[n-1])res += P[n-1]+1, x-= (2+L[n-1]),n--;
        else if(x == 1+ L[n-1]){
            res += P[n-1];
            x = 0;
            break;
        }
        else{
            x -= 1;
            n--;
        }
    }
    cout << res + (bool)x<< endl;

}

#undef int
int main() {
#if __MINGW32__
    freopen("C:\\Users\\hiroo\\CLionProjects\\competitive\\Input.txt", "r", stdin);
    freopen("C:\\Users\\hiroo\\CLionProjects\\competitive\\Output.txt", "w", stdout);

#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    _();

}