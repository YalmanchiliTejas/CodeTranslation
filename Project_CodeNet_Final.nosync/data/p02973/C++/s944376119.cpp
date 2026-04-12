#include <iostream>
#include <tuple>
#include <algorithm>

int get_smaller_max(int a, int l[], int l_count) {
    int* ptr = std::upper_bound(l, l + l_count, a, std::greater<int>());
    int index = ptr - l;
    if (index == l_count) return -1;
    return index;
}

int main() {
    int n; std::cin >> n;

    int l[n], l_count = 0, max, index;
    for (size_t i = 0; i < n; i++) {
        int a; std::cin >> a;
        int index = get_smaller_max(a, l, l_count);
        if (index == -1) {
            l[l_count] = a;
            l_count++;
        } else {
            l[index] = a;
        }
    }

    std::cout << l_count << std::endl;
    return 0;
}
