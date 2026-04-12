#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

char s[10];

int main(void) {
    std::scanf("%s", s);
    for (int i = 0; s[i + 1] != '\0'; i++) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            std::puts("Yes");
            return 0;
        }
    }
    std::puts("No");
    return 0;
}