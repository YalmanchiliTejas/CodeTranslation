#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;

int n;
int a[maxN], answer[maxN];

int main() {
 //   freopen("input.in", "r", stdin);
  //  freopen("output.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    int low = 1, high = n, id = 0;
    for (int i = n; i > 0; --i) {
        if (id) {
            answer[high--] = a[i];
        } else {
            answer[low++] = a[i];
        }
        id = 1 - id;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", answer[i]);

    return 0;
}
