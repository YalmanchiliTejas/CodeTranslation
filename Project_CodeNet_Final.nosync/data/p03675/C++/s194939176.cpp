#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
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
    scanInt(N);
    deque<int> seq;
    loop(i, N){
        scanInt(ai);
        if (i % 2 == 1){
            seq.emplace_front(ai);
        }else{
            seq.emplace_back(ai);
        }
    }
    if (N % 2 == 1){
        loop(i, N - 1){
            printf("%d ", seq[N - 1 - i]);
        }
        printf("%d\n", seq.front());
    }else{
        loop(i, N - 1){
            printf("%d ", seq[i]);
        }
        printf("%d\n", seq.back());
    }
}
