#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define SINV(t) greater<t>()
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP2(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
#define vv(t) vector<t>

template<typename T>
void SV(vector<T> v){
    REP(i,v.size()){
        #ifdef LOCAL
            cout << i << " : " << v[i] << endl;
        #endif
    }
}

int bitCount(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >> 16);
}

int main(){
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll money = 0;
    if(X > Y){
        money = min(A*Y+B*Y, C*2*Y);
        X-=Y;
        money += min(A*X, C*2*X);
    }else{
        money = min(A*X+B*X, C*2*X);
        Y-=X;
        money += min(B*Y, C*2*Y);
    }
    cout << money << endl;
    return 0;
}
