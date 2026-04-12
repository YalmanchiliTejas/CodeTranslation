#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <limits>
#include <cmath>
#include <cassert>

using namespace std;
using ll = long long;

const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl

char M(char a, char b)
{
    if(a == 'T' and b == 'T') return 'T';
    if(a == 'T' and b == 'F') return 'F';
    if(a == 'F' and b == 'T') return 'T';
    return 'T';
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<char> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 1; i < N; i++)
    {
        P[i] = M(P[i - 1], P[i]);
    }
    cout << P[N - 1] << endl;
    return 0;
}


