#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define NFOR(i,a,b) for(int i = (int)(a); i >= (int)(b); --i)
#define endl "\n"
#define mp make_pair
#define X first
#define Y second
#define inf 1e9
#define mod 1000000007
#define pb push_back
#define Case cout<<"Case #"<<++cas<<": ";
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()
#define sz(x) int(x.size())
// #define lli int
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<lli,lli> pll;
typedef vector<lli> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef complex <long double> complex_t;
const long double PI = acos((long double)-1.0);

#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

vector<pair<pii,int>> edges;
int par[100010];
int child1[100010];
vector<pair<pii,int>> points;
ll answer1 = 0;

int getParent(int v) {
    while (v != par[v]) {
        v = par[v];
    }
    return v;
}

bool union1(int u, int v) {
    u = getParent(u), v = getParent(v);
    if (u == v) return false;
    if (child1[u] > child1[v]) {
        par[v] = par[u], child1[u] += child1[v];
    } else {
        par[u] = par[v], child1[v] += child1[u];
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    FOR(i, 1, n) {
        child1[i] = 1, par[i] = i;
    }
    FOR(i, 1, n) {
        int a1, b1; cin >>a1 >> b1;
        points.pb(mp(mp(a1, b1), i));
    }
    sort(all(points), [](const pair<pii,int> &a, const pair<pii,int> &b) {
        return a.first.first < b.first.first;
    });
    FOR(i, 0, n-2) {
        edges.pb(mp(mp(points[i].second, points[i+1].second), points[i+1].first.first - points[i].first.first));
    }
    sort(all(points), [](const pair<pii,int> &a, const pair<pii,int> &b) {
        return a.first.second < b.first.second;
    });
    FOR(i, 0, n-2) {
        edges.pb(mp(mp(points[i].second, points[i+1].second), points[i+1].first.second - points[i].first.second));
    }
    sort(all(edges), [](const pair<pii,int> &a, const pair<pii,int> &b) {
        return a.second < b.second;
    });
    for (auto edge :edges) {
        if (union1(edge.first.first, edge.first.second)) {
            answer1 += edge.second;
        }
    }
    cout << answer1 << endl;
return 0;}