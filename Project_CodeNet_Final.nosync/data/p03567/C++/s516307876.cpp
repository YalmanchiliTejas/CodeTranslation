#include <bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#ifdef _WIN32
#include <windows.h>
#define print(x) PRINT(x, #x)
template<typename T> inline const void PRINT(T VARIABLE, string NAME)
{
#ifndef ONLINE_JUDGE /// ONLINE_JUDGE IS DEFINED ON CODEFORCES
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cerr << NAME << " = " << VARIABLE;
    SetConsoleTextAttribute(hConsole, 7);
    cerr << '\n';
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
        auto h1 = hash<T1> {}(p.first);
        auto h2 = hash<T2> {}(p.second);
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
    cout << "-1\n";
    exit(0);
}
const int NMAX = 3 * 1e5 + 5;
const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const double PI = atan(1) * 4;
const double EPS = 1e-12;
const int seed = 1e3 + 7;


string s;
int main()
{
    FASTIO;
    cin >> s;
    for0(i, s.size() - 1) if(s[i] == 'A' && s[i + 1] == 'C') return cout << "Yes",0;
    cout << "No";
    return 0;
}


