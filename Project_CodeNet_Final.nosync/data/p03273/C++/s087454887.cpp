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
#define REP(n) for(int i=0; i<(n); i++)
#define REPj(n) for(int j=0; j<(n); j++)
#define REPinit(i,a,n) for(int i=(a); i<(n); i++)
#define REPinitj(j,a,n) for(int j=(a); j<(n); j++)

//algorithm
//#define SORT(c) sort((c).begin(),(c).end())

//constant

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//Optimizer
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* 
	add utility Algorithm
*/

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<vector<char>> blocks(H, vector<char>(W, '.'));

    vector<int> dispRow;
    vector<int> dispCol;
    vector<char> tmpBlocks;

    REPinit(i, 0, H) {
        REPinit(j, 0, W) {
            cin >> blocks[i][j];
            if (blocks[i][j] == '#') {
                dispRow.push_back(i);
                dispCol.push_back(j);
            }
        }
    }
    
    REPinit(i, 0, H) {
        if(std::find(dispRow.begin(), dispRow.end(), i) == dispRow.end()) continue;
        REPinit(j, 0, W) {
            if(std::find(dispCol.begin(), dispCol.end(), j) == dispCol.end()) continue;
            cout << blocks[i][j];
        }
        cout << endl;
    }

    return 0;
}
