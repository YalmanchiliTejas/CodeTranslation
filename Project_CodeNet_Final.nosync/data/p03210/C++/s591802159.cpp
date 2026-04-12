#include <bits/stdc++.h>

int X;

int main() {
    std::cin >> X;
    std::string s;
    if ( X == 7 || X == 5 || X == 3 ) {
        s = "YES";
    } else {
        s = "NO";
    }
    std::cout << s << std::endl;
    return 0;
}
