#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
//#define int ll
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

#ifdef RUS_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

const double PI = 2 * acos(0.0);
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1>
inline istream & operator >> (istream &in, pair<T0, T1> &a) {
    return in >> a.first >> a.second;
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef RUS_HOME
    freopen("input", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef RUS_HOME
    cout << "\n\n\n\nTOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

const int N=1e5+100;
vi g[N];
int dp[N],ans[N];

void dfs(int v, int pr){
    int w=0,cnt=0,l=0;
    for(auto p:g[v]){
        if(p==pr)
            continue;
        dfs(p,v);
        w+=(dp[p]==1);
        l+=(dp[p]==3);
        cnt++;
    }
    if(cnt==0){
        dp[v]=3;
    }else if(w>=1||l>=2){
        dp[v]=1;
    } else if(l==1)
        dp[v]=0;
    else
        dp[v]=3;
}

void dfs(int v,int pr,int kek){
    int w=(kek==1),l=(kek==3);
    for(auto p:g[v]){
        if(p==pr)
            continue;
        w+=(dp[p]==1);
        l+=(dp[p]==3);
    }
    if(w>=1||l>=2){
        ans[v]=1;
    }
    for(auto p:g[v]){
        if(p==pr)
            continue;
        if(g[v].size()==1)
            dfs(p,v,3);
        else{
            w-=(dp[p]==1);
            l-=(dp[p]==3);
            if(w>=1||l>=2){
                dfs(p,v,1);
            }else if(l==1){
                dfs(p,v,0);
            }else{
                dfs(p,v,3);
            }
            w+=(dp[p]==1);
            l+=(dp[p]==3);
        }
    }

}

void smain() {

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int lol=1;
    for(int i=1;i<=n;i++){
        if(g[i].size()!=1)
            lol=i;
    }

    dfs(lol,lol);
    dfs(lol,lol,0);

    int fl=0;
    for(int i=1;i<=n;i++){
        fl|=ans[i];
    }
    if(fl){
        cout<<"First";
    }else{
        cout<<"Second";
    }




}