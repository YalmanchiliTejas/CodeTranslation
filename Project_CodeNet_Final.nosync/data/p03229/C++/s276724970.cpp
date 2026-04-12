//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <cctype>
#include <complex>
#include <regex>

using namespace std;

#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

int main() {

    long long N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            if (i == 0) B[i] = 1;
            else if (i == N - 1) B[i] = 1;
            else B[i] = 2;
        }
        if (i % 2 == 1) {
            if (i == 0) B[i] = -1;
            else if (i == N - 1) B[i] = -1;
            else B[i] = -2;
        }
    }


    long long ans1 = 0, ans2 = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) ans1 += A[i] * B[i];
    for (int i = 0; i < N; i++) B[i] *= -1;
    reverse(B.begin(), B.end());
    for (int i = 0; i < N; i++) ans2 += A[i] * B[i];

    cout << max(ans1, ans2) << endl;

}











































