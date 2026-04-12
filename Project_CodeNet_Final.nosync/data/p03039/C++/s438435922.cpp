/*
ID: hepic
PROG: sabotage
LANG: C++11
*/
#include <bits/stdc++.h>

#define FOR(i, a, b) for(auto i=a; i<=b; ++i)
#define REP(i, a, b) for(auto i=a; i<b; ++i)
#define FORI(i, a, b) for(auto i=a; i!=b+1-2*(a>b); i+=1-2*(a>b))
#define REPI(i, a, b) for(auto i=a-(a>b); i!=b-(a>b); i+=1-2*(a>b))
#define ALL(v) v.begin(),v.end()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a, b) emplace_back(a, b)
#define fir first
#define sec second
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define type(x) typeid(x).name()
#define ms(arr, val) memset(arr, val, sizeof(arr))
#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
#define PI acos(-1)
#define open_read freopen("disrupt.in", "r", stdin)
#define open_write freopen("disrupt.out", "w", stdout)

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef pair<int, int> PII;
typedef pair<int, PII> PIPII;
typedef pair<PII, PII> PPIIPII;
typedef pair<LL, LL> PLL;
typedef pair<ULL, ULL> PUU;
typedef pair<LL, PLL> PLPLL;
typedef pair<PLL, PLL> PPLLPLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;


template<typename T, typename T1>
ostream& operator << (ostream &out, pair<T, T1> obj) {
    out << "(" << obj.first << ", " << obj.second << ")";
    return out;
}


template<typename T, typename T1>
ostream& operator << (ostream &out, map<T, T1> cont) {
    typename map<T, T1>::const_iterator itr = cont.begin();
    typename map<T, T1>::const_iterator ends = cont.end();

    for(; itr != ends; ++itr) {
        out << *itr << " ";
    }

    out<<endl;
    return out;
}


template<typename T>
ostream& operator << (ostream &out, set<T> cont) {
    typename set<T>::const_iterator itr = cont.begin();
    typename set<T>::const_iterator ends = cont.end();
    
    for(; itr != ends; ++itr) {
        out << *itr << " ";
    }

    out << endl;
    return out;
}


template<typename T>
ostream& operator << (ostream &out, multiset<T> cont) {
    typename multiset<T>::const_iterator itr = cont.begin();
    typename multiset<T>::const_iterator ends = cont.end();

    for (; itr != ends; ++itr) {
        out << *itr << " ";
    }

    out << endl;
    return out;
}


template<typename T, template<typename ELEM, typename ALLOC=allocator<ELEM>> class CONT>
ostream& operator << (ostream &out, CONT<T> cont) {
    typename CONT<T>::const_iterator itr = cont.begin();
    typename CONT<T>::const_iterator ends = cont.end();

    for (; itr != ends; ++itr) {
        out << *itr << " ";
    }

    out << endl;
    return out;
}


template<typename T, unsigned int N, typename CTy, typename CTr>
typename enable_if<!is_same<T, char>::value, basic_ostream<CTy, CTr> &>::type
operator << (basic_ostream<CTy, CTr> &out, const T (&arr)[N]) {
    REP (i, 0, N) {
        out << arr[i] << " ";
    }

    out << endl;
    return out;
}


template<typename T>
T GCD(T a, T b) {
    T min_v = min(a, b);
    T max_v = max(a, b);

    while (min_v) {
        T temp = max_v % min_v;
        max_v = min_v;
        min_v = temp;
    }

    return max_v;
}


template<typename T>
T LCM(T a, T b) {
    return (a*b) / gcd(a, b);
}


template<typename T>
T fastExpPow(T base, T exp, T mod) {
    T res = 1;

    while (exp) {
        if (exp&1) {
            res *= base;
            res %= mod;
        }

        exp >>= 1;
        base *= base;
        base %= mod;
    }

    return res % mod;
}

/*#################################################################################################################
###################################################################################################################
###################################################################################################################
#################################################################################################################*/

#define MOD 1000000007LL
#define SIZE 200010

int N, M, K;
LL sumAllpairs, answer;
LL fact[SIZE];


int main() {
    scanf("%d%d%d", &N, &M, &K);
    
    LL val = ((N - 1 + MOD) * N) % MOD;
    val = (val * (N + 1)) % MOD;
    val = (val * M) % MOD;
    val = (val * M) % MOD;
    sumAllpairs += val;
    
    val = ((M - 1 + MOD) * M) % MOD;
    val = (val * (M + 1)) % MOD;
    val = (val * N) % MOD;
    val = (val * N) % MOD;

    sumAllpairs = (sumAllpairs + val) % MOD;
    sumAllpairs = (sumAllpairs * fastExpPow(6LL, MOD - 2LL, MOD)) % MOD;
    
    fact[0] = fact[1] = 1;

    FOR (i, 2, N * M) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    answer = (fact[N * M - 2] * fastExpPow(fact[K - 2], MOD - 2LL, MOD)) % MOD;
    answer = (answer * fastExpPow(fact[N * M - K], MOD - 2LL, MOD)) % MOD;
    answer = (answer * sumAllpairs) % MOD;

    printf("%lld\n", answer);
    return 0;
}