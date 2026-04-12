#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#ifdef _MSC_VER
int debug = 1;
#else
int debug = 0;
#endif

int main() {
    int n;
    cin >> n;
    auto a = vector<int>(n);
    for (auto &a_i : a)
        cin >> a_i;

    auto minset = multiset<int, greater<int>>();

    for (int i = 0; i < n; i++) {
        auto v = a[i];

        if (debug)
            cerr << "current value " << v << ", ";

        auto itr = minset.upper_bound(v);
        if (itr == minset.end()) {
            minset.insert(v);
            if (debug)
                cerr << "new set\n";

        } else {
            if (debug)
                cerr << "append to " << *itr << "\n";
            minset.erase(itr);
            minset.insert(v);
        }
    }

    if (debug) {
        for (auto m : minset)
            cerr << m << ", ";
        cerr << "\n";
    }

    cout << minset.size();
    return 0;
}
