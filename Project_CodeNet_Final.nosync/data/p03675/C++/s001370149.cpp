#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, j = 0;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%d", a.begin() + i);
    for (int i = n - 1; i >= 0; i -= 2, ++j) b.at(j) = a.at(i);
    for (int i = n % 2; i < n; i += 2, ++j) b.at(j) = a.at(i);
    for (int i = 0; i < n - 1; ++i) printf("%d ", b.at(i));
    printf("%d\n", b.back());
    return 0;
}
