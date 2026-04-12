#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 25;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] < a[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}