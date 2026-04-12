# include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int a[n]; for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int num_query, k; scanf("%d", &num_query);
    
    for (int i = 0; i < num_query; ++i) {
        scanf("%d", &k);
        int result = lower_bound(a, a + n, k) - a;
        printf("%d\n", result);
    }
    return 0;
}
