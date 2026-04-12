#include "bits/stdc++.h"
using namespace std;

// GNU C Compiler
//template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }


/*
--------------------------------------------

	type

--------------------------------------------
*/
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
//using pair<T1, T2> = p12;

/*
--------------------------------------------

	container

--------------------------------------------
*/
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
#define ALL(v) v.begin(),v.end()

/*
--------------------------------------------

	repetition

--------------------------------------------
*/
#define REP(n) for(int i=0; i<n; i++)
#define REPj(n) for(int j=0; j<n; j++)
#define REPinit(a,n) for(int i=a; i<n; i++)
#define REPinitj(a,n) for(int j=a; j<n; j++)

//algorithm
//#define SORT(c) sort((c).begin(),(c).end())

/*
--------------------------------------------

	constant

--------------------------------------------
*/
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

/*
--------------------------------------------

	Optimizer

--------------------------------------------
*/
//#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/*
--------------------------------------------
 
	Utility Algorithm

-------------------------------------------- 
*/

template <typename T>
void swapAlgorithm(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
 
template <typename T1>
T1 euclideanAlgorithm(T1 a, T1 b) {
    T1 a_tmp = a;
    T1 b_tmp = b;
 
    if (a_tmp > b_tmp) {
        swapAlgorithm<T1>(a_tmp, b_tmp);
    }
 
    T1 r = a_tmp % b_tmp;
    while (r != 0) {
        a_tmp = b_tmp;
        b_tmp = r;
        r = a_tmp % b_tmp;
    }
    return b_tmp;    
}

template <typename T2>
T2 getLCM(T2 a, T2 b) {
    return (a * b)/(euclideanAlgorithm(a, b));
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(int argc, char const *argv[])
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;

    if(n==m) cout << "Yes";
    else cout << "No";
    
    return 0;
}
