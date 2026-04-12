#include "bits/stdc++.h"
using namespace std;

// GNU C Compiler
//template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

// type
using ll = int_fast64_t;
using ull = uint_fast64_t;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
//using pair<T1, T2> = p12;

//container
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
#define ALL(v) v.begin(),v.end()

//repetition
#define REP(n) for(ll i=0; i<(n); i++)
#define REPj(n) for(ll j=0; j<(n); j++)
#define REPinit(i,a,n) for(ll i=(a); i<(n); i++)
#define REPinitj(j,a,n) for(ll j=(a); j<(n); j++)

//algorithm
#define SORT(c) sort((c).begin(),(c).end())
#define CONTAINER_ALL(a) a.begin(),a.end()

//constant

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//Optimizer
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    cin >> X;

    switch (X)
    {
    case 3:
    case 5:
    case 7:
        cout << "YES" << endl;
        break;
    default:
        cout << "NO" << endl;
        break;
    }

    
    return 0;
}
