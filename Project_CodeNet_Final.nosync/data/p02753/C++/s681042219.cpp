/*Bismillahir Rahmanir Raheem*/

#include <bits/stdc++.h>
using namespace std;

//constant
#define PI acos(-1.0)

//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned un;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef map<char, char> mcc;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef map<ll, ll> mll;

// defined for taking input
#define gl(x) getline(cin, x)
#define sf scanf
#define sfi(x) scanf("%d", &x)
#define sfc(x) scanf("%c", &x)
#define sfl(x) scanf("%lld", &x)
#define sflu(x) scanf("%llu", &x)
#define sfii(x, y) scanf("%d %d", &x, &y)
#define sfll(x, y) scanf("%lld %lld", &x, &y)
#define sfiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sflll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)

//defined for printing
#define pf printf
#define pfn pf("\n")
#define pfcas pf("Case %d: ", cas)
#define pfyes pf("Yes");
#define pfno pf("No");
#define pfi(x) pf("%d", x)
#define pfl(x) pf("%lld", x)

//defined for loop

//increament
#define loopi(i, j, k) for (int i = j; i < k; i++)
#define loopl(i, j, k) for (ll i = j; i < k; i++)
#define loopc(i, j, k) for (char i = j; i < k; i++)
#define looplu(i, j, k) for (ull i = j; i < k; i++)
//decreament
#define loopri(i, j, k) for (int i = j; i > k; i--)
#define looprl(i, j, k) for (ll i = j; i > k; i--)
#define looprlu(i, j, k) for (ull i = j; i > k; i--)
#define looprc(i, j, k) for (char i = j; i > k; i--)
#define wa(t) while (t--)

//testcases
#define testc(t) for (char cas = 1; cas <= t; cas++)
#define testi(t) for (int cas = 1; cas <= t; cas++)
#define testl(t) for (ll cas = 1; cas <= t; cas++)

//some cmd
#define pb push_back
#define ppb pop_back
#define mp make_pair

//code start

int main()
{
    // freopen("/root/Programming/input.txt", "r", stdin);
    // freopen("/root/Programming/output.txt", "w", stdout);
    string str;
    cin>>str;
    if(str[1]!=str[2] or str[1]!=str[0]){
        pfyes;
    }
    else
    {
        pfno;
    }
    pfn;
    
    return 0;
}