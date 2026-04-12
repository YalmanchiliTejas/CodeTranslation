#include <bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define FASTIO ios_base::sync_with_stdio(0)
using namespace std;
#ifdef _WIN32
#include <windows.h>
#define print(x) PRINT(x, #x)
template<typename T> inline const void PRINT(T VARIABLE, string NAME)
{
#ifndef ONLINE_JUDGE /// ONLINE_JUDGE IS DEFINED ON CODEFORCES
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cerr << NAME << " = " << VARIABLE << '\n';
    SetConsoleTextAttribute(hConsole, 7);
#endif
}
#else
#define print(x) 0
#endif
struct pair_hash
{
    template<typename T1, typename T2>
    size_t operator () (const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};
typedef long long ll;
typedef unsigned long long ull;
const ll INFLL = 2 * (ll)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
//ifstream fin(".in");
//ofstream fout(".out");
void die()
{
    cout << "NO";
    exit(0);
}
const int NMAX = 1e5 + 5;
const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const double PI = atan(1) * 4;
const double EPS = 1e-12;

int n, k;
ll v[55];
ll scad[NMAX];
ll adun;


int main()
{
    FASTIO;
    cin >> n;
    for1(i, n) cin >> v[i];
    while(1)
    {
        bool no = 0;
        for1(i, n)
        {
            if(v[i] >= n) no = 1;
           // print(scad[i]);
           // print(adun);
           // v[i] += adun - scad[i];
           // print(v[i]);
           // scad[i] += v[i] / n + adun;
            adun += v[i] / n;
            for1(j, n) if(j != i) v[j] += v[i] / n;
            v[i] = v[i] % n;
        }
        for1(i, n) if(v[i] >= n) no = 1;
        if(!no) return cout << adun, 0;
       // print(adun);
       // print('\n');
    }


    return 0;
}

/*
3
3 4 5
*/
