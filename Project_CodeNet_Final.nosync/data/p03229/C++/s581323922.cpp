#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const long long LINF = 1000000000000000000; // 1e18
const double EPS = 1E-10;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}




int main(){
    int N; std::cin >> N;
    std::vector<int> A(N), pt0(N), pt1(N);
    for(int i(0); i < N; ++i){
        std::cin >> A[i];
        int a(2), sgn((i%2)*2-1);
        if(i == 0 || i == N-1) a = 1;
        pt0[i] = a * sgn;
        pt1[i] = -pt0[i];
    }
    std::sort(A.rbegin(), A.rend());
    std::sort(pt0.rbegin(), pt0.rend());
    std::sort(pt1.rbegin(), pt1.rend());
    long long sum0(0), sum1(0);
    for(int i(0); i < N; ++i){
        sum0 += A[i] * pt0[i];
        sum1 += A[i] * pt1[i];
    }
    std::cout << std::max(sum0, sum1) << std::endl;
    return 0;
}
