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
    scanInt(r);
    scanInt(g);
    scanInt(b);
    const int num = r * 100 + g * 10 + b;
    if (num % 4 == 0){
        puts("YES");
    }else{
        puts("NO");
    }
}
