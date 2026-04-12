#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;

long long M = 1000000007;


int main() {
    int N;
    cin >> N;
    long long res = 0;
    vector<long long> vs;

    long long AA = 0;
    for (int i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        vs.push_back(A);
        AA += A;
        AA %= M;
    }

    for (int i = 0; i < N - 1; ++i) {

        AA -= vs[i];
        if(AA < 0) {
            AA += M;
        }
        AA %= M;

        long long tmp = vs[i] * AA;
        tmp %= M;
        res += tmp;
        res %= M;
    }
    cout << res << endl;
}