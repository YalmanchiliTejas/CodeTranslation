#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> h, int index) {
    int val = h[index];
    for (int i = 0; i < index; i++) {
        if (h[i] > val) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> h = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    int cnt = 1;
    for (int i = 1 ; i < n; i++) {
        if (check(h, i)) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
