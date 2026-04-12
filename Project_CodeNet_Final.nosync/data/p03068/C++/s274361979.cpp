#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    string S;
    int N, K;
    cin >> N >> S >> K;
    for (int i = 0; i < N; i++) {
        cout << (S[i] != S[K - 1] ? '*' : S[i]);
    }
    cout << endl;
    return 0;
}