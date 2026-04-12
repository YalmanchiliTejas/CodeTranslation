#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

int main() {
    int N;
    cin >> N;
    vector<int> v(N), origin(N);
    REP(i, 0, N) {
        cin >> v[i];
        origin[i] = v[i];
    }
    sort(begin(v), end(v));
    REP(i, 0, N) {
        int ind = lower_bound(begin(v), end(v), origin[i]) - begin(v);
        if (ind < N / 2) {
            cout << v[N / 2] << endl;
        } else {
            cout << v[N / 2 - 1] << endl;
        }
    }
    return 0;
}