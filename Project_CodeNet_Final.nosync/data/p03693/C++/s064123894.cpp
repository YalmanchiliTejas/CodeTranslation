#include <iostream>

class RDBCards {
public:
    bool printCards(int a, int b, int c) {
        int result = a * 100 + b * 10 + c * 1;
        if ((result % 4) == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char** argv) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    RDBCards r0;
    if (r0.printCards(a, b, c)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
