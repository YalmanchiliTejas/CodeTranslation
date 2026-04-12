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

#define REP(i, N) for (int i = 0; i < (N); ++i)
#define scanInt(x) int x; scanf("%d", &(x)); getchar();
#define scanLLInt(x) ll x; scanf("%lld", &(x)); getchar();
#define scanVecInt(A, N) vector<int> A(N); REP(i, N){scanf("%d", &(A[i])); getchar();}
#define scanVecLLInt(A, N) vector<ll> A(N); REP(i, N){scanf("%lld", &(A[i])); getchar();}

int main()
{
    string S;
    cin >> S;
    if (S.find("AC") != string::npos){
        puts("Yes");
    }else{
        puts("No");
    }
}
