#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <cmath>
#define INF 987654321
#define INT_MAX 2147483647
#define MIN(a, b) ((a) < (b) ? a : b)
#define MAX(a, b) ((a) > (b) ? a : b)
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    unsigned long int mod = 1000000007;
    vector<unsigned long int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    unsigned long int segsum, ret;
    segsum = 0;
    ret = 0;

    for(int i = N-1; i > 0; i--) {
        segsum = (segsum + A[i]) % mod;
        ret = (ret % mod + (segsum * A[i-1]) % mod) % mod;
    }
    cout << ret;
}