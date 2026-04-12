#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9+7;

int main(void) {
    ll N;
    cin >> N;
    vector <int>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll s = 0;
    ll x = 0;
    for (int i = N-2; i >= 0 ; i--) {
        // s += A[i+1];
        s = (s + A[i+1]) % MOD;
        // x = x + s * A[i];
        x = (x + ((s * A[i]) % MOD)) % MOD;
    }
    cout << x << endl;
    return 0;
}

