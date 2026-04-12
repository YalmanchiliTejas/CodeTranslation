#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    size_t k;
    cin >> k;

    vector<int64_t> dp_less(k + 1, 0);
    vector<int64_t> dp_equal(k + 1, 0);
    dp_equal[0] = 1;

    for (const auto &dig : str) {
        vector<int64_t> next_dp_less(k + 1, 0);
        vector<int64_t> next_dp_equal(k + 1, 0);

        for (size_t i = 0; i <= k; i += 1) {
            next_dp_less[i] = dp_less[i];
            if (dig > '0') {
                next_dp_less[i] += dp_equal[i];
            }
            if (i > 0) {
                next_dp_less[i] += dp_less[i - 1] * 9;
            }
            if (i > 0 && dig > '0') {
                next_dp_less[i] += dp_equal[i - 1] * (dig - '1');
            }

            if (dig == '0') {
                next_dp_equal[i] = dp_equal[i];
            } else if (i > 0) {
                next_dp_equal[i] = dp_equal[i - 1];
            }
        }

        dp_less = next_dp_less;
        dp_equal = next_dp_equal;
    }

    cout << dp_less[k] + dp_equal[k] << "\n";
    return 0;
}
