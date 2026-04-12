#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int n = 0; n < N; ++n) cin >> A[n];

    multiset<int> maxes;
    for(auto a: A) {
        if (maxes.size() == 0) {
            maxes.insert(a);
        }
        else {
            if (a <= *maxes.begin()) {
                maxes.insert(a);
            }
            else {
                // auto it = lower_bound(maxes.begin(), maxes.end(), a);
                auto it = maxes.lower_bound(a);
                --it;
                maxes.erase(it);
                maxes.insert(a);
            }
        }
        // for(auto a: maxes) cout << a << ","; cout << endl;
    }
    cout << maxes.size() << endl;
}

