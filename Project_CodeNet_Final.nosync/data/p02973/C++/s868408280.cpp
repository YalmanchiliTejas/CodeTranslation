#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);

    int n; cin>>n;
    vector<int64_t> a(n);
    for (auto &r: a) {
        cin>>r;
    }

    multiset<int64_t> ss;

    for (auto &r: a) {
        // cout << "* " << ss.size() << endl;
        // for (auto &s: ss) {
        //     cout << "  * " << s << endl;
        // }

        auto it = ss.upper_bound(-r);
        if (it == ss.end()) {
            ss.insert(-r);
        } else {
            ss.erase(it);
            ss.insert(-r);
        }
    }

    cout << ss.size() << endl;

    return 0;
}