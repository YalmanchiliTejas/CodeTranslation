#include <bits/stdc++.h>

using namespace std;

using ll = int_fast64_t;
constexpr ll llmax = INT_FAST64_MAX; // std::numeric_limits<int_fast64_t>::max()
constexpr ll llmin = INT_FAST64_MIN; // std::numeric_limits<int_fast64_t>::min()
using ull = uint_fast64_t;
constexpr ull ullmax = UINT_FAST64_MAX; // std::numeric_limits<uint_fast64_t>::max()

#define FOR(i, b, e) for (int i = (b); i < (e); ++i)
#define RFOR(i, b, e) for (int i = ((e) - 1); (b) <= i; --i)
#define REP(i, N) for (int i = 0; i < (N); ++i)
#define RREP(i, N) for (int i = ((N) - 1); 0 <= i; --i)
#define scanInt(x) int x; scanf("%d", &(x)); getchar();
#define scanLLInt(x) ll x; scanf("%lld", &(x)); getchar();
#define scanVecInt(A, N) vector<int> A(N); REP(i, N){scanf("%d", &(A[i])); getchar();}
#define scanVecLLInt(A, N) vector<ll> A(N); REP(i, N){scanf("%lld", &(A[i])); getchar();}

int main()
{
    scanInt(N);
    scanVecInt(H, N);
    int leftmax = 0;
    int count = 0;
    for (auto&& h : H){
        if (leftmax <= h) count++;
        leftmax = max(leftmax, h);
    }
    cout << count << endl;
}
