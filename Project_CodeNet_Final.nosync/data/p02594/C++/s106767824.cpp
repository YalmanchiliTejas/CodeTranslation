#include <bits/stdc++.h>
using namespace std;
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){ os << "{ "; for(auto s:S) os<<s<<" ";return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) { return os << "(" << P.first << "," << P.second << ")";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) { os << "{ "; for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") "; return os<<"}"; }
#ifdef LMAO
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){ const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | "; __f(comma+1, args...); }
#else
    #define trace(...) 42
#endif
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define tcase int tt; cin>>tt; while(tt--)
#define tcase2 int tt; cin>>tt; for(int qq=1;qq<=tt;qq++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef  unsigned long long int ull;
typedef long double ld;
const int MAX = 1000010;
const int MOD2 = 998244353;
const int MOD = 1000000007; 
const int INF = 1e8;    
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-7;
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)   
/*****************start************/

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(25);cerr<<fixed<<setprecision(10);
    int x;
    cin>>x;
    if(x>=30)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    return 0;
}
