#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;

const long long mod = 1000000007;

int main(){
    long long N;
    cin >> N;
    vector<unsigned long long> A(N + 1);
    cin >> A.at(1);
    vector<unsigned long long> S(N + 1);
    S.at(1) = A.at(1);
    for(long long i = 2; i <= N; i++){
        cin >> A.at(i);
        S.at(i) = S.at(i - 1) + A.at(i);
    }
    unsigned long long sum = 0;
    for(long long i = 1; i <= N; i++){
        sum += (A.at(i) % mod) * ((S.at(N) - S.at(i)) % mod);
      sum = sum % mod;
    }

    cout << sum % mod << endl;
}