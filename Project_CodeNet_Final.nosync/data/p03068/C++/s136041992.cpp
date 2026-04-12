#include <iostream>

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> s >> k;
    char nonreplace_char = s[k-1];
    for (int i = 0; i < n; ++i) {
        if (s[i] != nonreplace_char) {
            s[i] = '*';
        }
    }
    std::cout << s << std::endl;
}
