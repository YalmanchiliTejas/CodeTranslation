#include <iostream>

int main() {
    long long K, A, B, k;
    std::cin >> K >> A >> B;
    k = K - A;

    if(k <= 0) {
        printf("1\n");
    } else if(A - B <= 0) {
        printf("-1\n");
    } else if (k % (A - B) == 0) {
        printf("%lld\n", (k / (A - B)) * 2 + 1);
    } else {
        printf("%lld\n", (k / (A - B) + 1) * 2 + 1);
    }

    return 0;

}

