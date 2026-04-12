/*                                 ___ _____ 
  ___  _ __ ___   ___  __ _  __ _ / _ \___  |
 / _ \| '_ ` _ \ / _ \/ _` |/ _` | | | | / / 
| (_) | | | | | |  __/ (_| | (_| | |_| |/ /  
 \___/|_| |_| |_|\___|\__, |\__,_|\___//_/   
                      |___/            
*/
// Getting better at it ! ! !
#include <bits/stdc++.h>
#include <string.h>
#define int long long
#define MAX (int)(1e7 + 5)
#define MAX2D (int)(1e3 + 5)
#define itn int
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sitr set<int>::iterator
#define mitr map<int, int>::iterator
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define vll vector<unsigned int>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                       \
    ios_base ::sync_with_stdio(0); \
    cin.tie(NULL);                 \
    cout.tie(NULL)
using namespace std;


void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define see(x...)
#endif

signed main()
{
    fast;
    int x;
    cin>>x;
    if(x >= 30) cout<<"Yes";
    else cout<<"No";
    return 0; 
}
 
/*
max factors number = 720720 --> 240 factors
max factors number = 1441440 -->288 factors
 
Beautiful program
Please run for me.
I've tried you in BASIC,
FORTRAN and C.
Beautiful program,
You've errors galore.
And each time I run you,
You're swapped out of core.
*/