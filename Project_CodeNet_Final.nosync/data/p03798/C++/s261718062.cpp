#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>

#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}

bool get_third(bool first, bool second, char remark) {
    return (second && ((remark == 'o' && first) || (remark == 'x' && !first))) ||
            (!second && ((remark == 'o' && !first) || (remark == 'x' && first)));
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<bool> is_sheep(N);

    bool found = false;
    for (int flag = 0; flag < 4; ++flag) {
        is_sheep[0] = (flag >> 0) & 1;
        is_sheep[1] = (flag >> 1) & 1;
        for (int i = 2; i < N; ++i) {
            is_sheep[i] = get_third(is_sheep[i-2], is_sheep[i-1], s[i-1]);
        }
        if (is_sheep[N-1] == get_third(is_sheep[1], is_sheep[0], s[0]) &&
            is_sheep[0] == get_third(is_sheep[N-2], is_sheep[N-1], s[N-1])) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        string ans;
        for (int i = 0; i < N; ++i) {
            if (is_sheep[i]) {
                ans += "S";
            } else {
                ans += "W";
            }
        }
        cout << ans << endl;
    }

    return 0;
}
