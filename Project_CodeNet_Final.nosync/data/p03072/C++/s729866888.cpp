#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> h;

int main() {
    cin >> N; h.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &h[i]);
    int maxi = h[0];
    int count = 1;
    for (int i = 1; i < N; i++) {
        maxi = max(maxi, h[i-1]);
        if (maxi <= h[i]) count++;
    }
    cout << count << endl;
    return 0;
}