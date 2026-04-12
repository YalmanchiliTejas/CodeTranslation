#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    int x = 0;
    int y = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        x += 800;
        if ((i % 15) == 0) {
            y += 200;
        }
    }

    cout << x - y << endl;

    return 0;
}