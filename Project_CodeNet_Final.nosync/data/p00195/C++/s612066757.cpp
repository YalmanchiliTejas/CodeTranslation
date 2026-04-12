#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
constexpr char name[5]{'A', 'B', 'C', 'D', 'E'};

int main() {
    while (true) {
        int n_max = 0, name_idx;
        for (int i = 0; i < 5; ++i) {
            int a, p;
            cin >> a >> p;
            const int sum = a + p;
            if (sum == 0)
                exit(0);
            else if (sum > n_max) {
                n_max = sum;
                name_idx = i;
            }
        }
        cout << name[name_idx] << ' ' << n_max << endl;
    }
}
