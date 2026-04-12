#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;

    int max = 0;
    int res = 0;
    for (int n = 0; n < N; n++) {
        int H;
        cin >> H;

        if (H >= max) {
            res++;
            max = H;
        }
    }

    cout << res << endl;


    return 0;
}
