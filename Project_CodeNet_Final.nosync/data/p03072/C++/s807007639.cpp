#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

namespace {
using namespace std;
using ll = long long;
using ull = unsigned long long;
}

ll N;
vector<ll> H;

void input() {
    cin >> N;
    H.resize(N);
    for (auto& h : H)
        cin >> h;
}

ll solve() {
    ll height = H[0];
    ll count = 1;
    for (int i = 1; i < N; i++) {
        if (H[i] >= height) {
            height = H[i];
            count++;
        }
    }
    return count;
}

int main() {
    input();
    cout << solve() << endl;
    
    return 0;
}

