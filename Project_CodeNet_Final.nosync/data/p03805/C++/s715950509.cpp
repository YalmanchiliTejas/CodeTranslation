#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

#define CIN(T, x) T x; cin >> x;
#define CINS(T, x, N) vector<T> x(N); for(int i = 0; i < (N); i++) { cin >> x[i]; }
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << "\n";
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << "\n";

int N, M;
vector<int> v[60];

int countPath(int node, vector<int> status) {

    int MAX = 0;
    for (int i = 0; i < N; i++) {
        MAX = max(MAX, status[i]);
    }

    if ( MAX == 0 ) {
        return 1;
    } else {
        int count = 0;
        for (int i = 0; i < v[node].size(); i++) {
            if ( status[v[node][i]] == 0 ) continue;
            vector<int> tempStatus = status;
            tempStatus[v[node][i]] = 0;
            count += countPath(v[node][i], tempStatus);
        }
        return count;
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> status(N, 1);
    status[0] = 0;

    cout << countPath(0, status) << "\n";
    return 0;
}