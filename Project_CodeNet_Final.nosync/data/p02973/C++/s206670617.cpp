#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    // vector<int> A(N);
    // for(int n = 0; n < N; ++n) cin >> A[n];

    multiset<int> maxes;
    for(int n = 0; n < N; ++n) {
        int a;
        cin >> a;

        auto it = maxes.lower_bound(a);

        if (it == maxes.begin()) {
            maxes.insert(a);
        }
        else {
            --it;
            maxes.erase(it);
            maxes.insert(a);
        }
        // for(auto a: maxes) cout << a << ","; cout << endl;
    }
    cout << maxes.size() << endl;
}
