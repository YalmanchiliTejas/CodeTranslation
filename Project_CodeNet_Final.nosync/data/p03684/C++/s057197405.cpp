// {{{
#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)x.size())
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
using LL=long long;
using PII=pair<int,int>;
using VI=vector<int>;

#ifdef FEI
template<typename T>
void _dump(const char* s, T&& head) { cerr<<s<<"="<<head<<endl; }
template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c=0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{') c++;
        if (*s==')' || *s==']' || *s=='}') c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1, tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, ##__VA_ARGS__); \
} while(0);

template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
    s<<'[';
    for (auto it=b; it!=e; it++) s<<(it==b?"":",")<<*it;
    s<<']';
    return s;
}

template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) { return s<<"("<<p.first<<","<<p.second<<")";}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &x) { return _out(s,ALL(x)); }
template<typename T, size_t N>
ostream& operator <<(ostream &s, const array<T,N> &x) { return _out(s,ALL(x)); }
template<typename T>
ostream& operator <<(ostream &s, const set<T> &x) { return _out(s,ALL(x)); }
template<typename A, typename B>
ostream& operator <<(ostream &s, const map<A,B> &x) { return _out(s,ALL(x)); }
#else
#define dump(...)
#endif

template<typename T>
void _R(T &x) { cin>>x; }
void _R(int &x) { scanf("%d",&x); }
void _R(LL &x) { scanf("%" PRId64,&x); }
void _R(double &x) { scanf("%lf",&x); }
void _R(char &x) { scanf(" %c",&x); }
void _R(char *x) { scanf("%s",x); }

void R(){}
template<typename T, typename... X>
void R(T& head, X&... tail) { _R(head); R(tail...); }

const int MOD = 1e9+7;
// }}}

const int N = 200005;
using TIIL = tuple<int, int, LL>;
int arr[N], par[N];
PII p[N];
vector<TIIL> edge;

LL dist(int a, int b) {
    return 1LL * min(abs(p[a].first - p[b].first), abs(p[a].second - p[b].second));
}

int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }

int main() {
    int n;
    R(n);

    for (int i=0; i<n; i++)
        R(p[i].first, p[i].second);

    for (int i=0; i<n; i++)
        arr[i] = par[i] = i;

    sort(arr, arr+n, [](const int &a, const int &b) {return p[a].first < p[b].first;});
    for (int i=1; i<n; i++)
        edge.push_back(make_tuple(arr[i-1], arr[i], dist(arr[i-1], arr[i])));

    sort(arr, arr+n, [](const int &a, const int &b) {return p[a].second < p[b].second;});
    for (int i=1; i<n; i++)
        edge.push_back(make_tuple(arr[i-1], arr[i], dist(arr[i-1], arr[i])));

    /*
    for (auto t : edge)
        dump(get<0>(t), get<1>(t), get<2>(t));
    */

    sort(edge.begin(), edge.end(), [](const TIIL &a, const TIIL &b) {
        return get<2>(a) < get<2>(b);});

    LL ans = 0;
    for (auto t : edge) {
        int a, b, c;
        tie(a, b, c) = t;

        if (find(a) == find(b)) continue;
        ans += c;
        par[find(a)] = find(b);
    }

    cout << ans << endl;


    return 0;
}
