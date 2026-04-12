#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
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
    scanInt(N);
    // vector<int> x(N);
    int min_xy = INT_MAX;
    int max_xy = 0;
    int min_greater_xy = INT_MAX;
    int max_less_xy = 0;
    multimap<int, int> blue_less;
    vector<int> y(N);
    loop(i, N){
        scanInt(xi);
        scanInt(yi);
        if (!(xi <= yi)) swap(xi, yi);
        // xi <= yi
        blue_less.emplace(xi, i);
        // x[i] = xi;
        y[i] = yi;
        min_xy = min(min_xy, xi);
        max_xy = max(max_xy, yi);
        min_greater_xy = min(min_greater_xy, yi);
        max_less_xy = max(max_less_xy, xi);
    }
    int min_sub = min(max_xy - min_greater_xy, max_less_xy - min_xy);
    set<int> blue_greater;
    loop(i, N - 1){
        blue_greater.emplace(y[blue_less.begin()->second]);
        blue_less.erase(blue_less.begin());
        min_sub = min(min_sub,
                      max(blue_less.rbegin()->first, *(blue_greater.rbegin())) - min(blue_less.begin()->first, *(blue_greater.begin())));
    }
    printf("%lld\n", min((static_cast<ll>(max_xy) - min_greater_xy) * (max_less_xy - min_xy),
                         (static_cast<ll>(max_xy) - min_xy) * min_sub));
}
