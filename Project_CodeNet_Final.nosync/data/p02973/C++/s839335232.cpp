#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = 1e5 + 7;
map<int, int> m;

int main() {
    int n;
    cin >> n;
    int cnt = n;
    while (n--) {
        int a;
        cin >> a;
        if (m.empty()) {
            m[-a]++;
        } else {
            auto p = m.upper_bound(-a);
            if (p != m.end()) {
                m[p->first]--;
                if (m[p->first] == 0) {
                    m.erase(p->first);
                }
                cnt--;
            }
            m[-a]++;
        }
    }
    cout << cnt << endl;
    return 0;
}
