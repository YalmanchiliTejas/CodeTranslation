
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;

using ll = long long int;

int main() {
    int N;
    vector<int> Hi;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        Hi.push_back(h);
    }

    int highest = Hi.front();
    int cnt = 0;
    for (const auto h : Hi) {
        if (h >= highest) {
            highest = h;
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}

