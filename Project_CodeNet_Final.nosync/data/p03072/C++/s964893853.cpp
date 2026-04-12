#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>


int main() {

    int N;
    std::cin >> N;

    std::vector<int> hs;

    for (int i = 0; i < N; i++) {
        int h;
        std::cin >> h;
        hs.push_back(h);
    }

    int cnt = 1;

    for (int i = 1; i < N; i++) {

        int h = hs[i];

        bool ok = true;

        for (int j = 0; j < i; j++) {

            if (hs[j] > h) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cnt += 1;
        }

    }

    std::cout << cnt << "\n";

    return 0;
}
