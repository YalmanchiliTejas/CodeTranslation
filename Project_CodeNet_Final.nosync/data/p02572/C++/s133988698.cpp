#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int pre;
int main() {
    int n;
    int mod = 1e9 + 7;
    while (~scanf("%d", &n)) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            sum = (sum + (long long)pre * a) % mod;
            pre = (pre + a) % mod;
        }
        printf("%d\n", sum);
    }
}
