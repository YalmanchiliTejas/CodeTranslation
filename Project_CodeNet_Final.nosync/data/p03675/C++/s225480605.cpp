#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
int a[200001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }
    if (n % 2 == 0) {
        for (int i = n - 1; i >= 1; i -= 2) printf("%d ", a[i]);
        for (int i = 0; i <= n - 2; i += 2) printf("%d ", a[i]);
    } else {
        for (int i = n - 1; i >= 0; i -= 2) printf("%d ", a[i]);
        for (int i = 1; i <= n - 2; i += 2) printf("%d ", a[i]);
    }
    puts("");
}