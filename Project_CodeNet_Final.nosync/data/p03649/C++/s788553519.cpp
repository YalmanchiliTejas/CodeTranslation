#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <memory>
#include <valarray>
#include <climits>

using namespace std;

using ll = long long int;

#define loop(i, N) for (int i = 0; i < N; ++i)
#define scanInt(x) int x; scanf("%d", &x); getchar();
#define scanLLInt(x) ll x; scanf("%lld", &x); getchar();
#define scanVecInt(A, N) vector<int> A(N); loop(i, N){scanf("%d", &(A[i])); getchar();}
#define scanVecLLInt(A, N) vector<ll> A(N); loop(i, N){scanf("%lld", &(A[i])); getchar();}

int main()
{
    scanLLInt(N);
    scanVecLLInt(A, N);
    ll result = 0;
    while (true){
        sort(A.begin(), A.end());
        // loop(i, N) printf("%lld ", A[i]); puts("");
        if (A.back() < N) break;
        if (N <= A.front()){
            const ll h = A.front() - N + 1;
            loop(i, N){
                A[i] -= h;
            }
            result += h * N;
        }else{
            const ll times = ((A[N - 1] - N) / N) + 1;
            loop(i, N - 1){
                A[i] += times;
            }
            A[N - 1] -= (times * N);
            result += times;
        }
    }
    printf("%lld\n", result);
}
