#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < n; i++)

struct Dice {
    int top, bottom, right, left, front, back;
    void reset() {
        top = 1, bottom = 6, right = 3, left = 4, front = 2, back = 5;
    }
    void operation(std::string s) {
        int tmp;
        if (s == "North") {
            tmp = top, top = front, front = bottom, bottom = back, back = tmp;
        } else if (s == "East") {
            tmp = top, top = left, left = bottom, bottom = right, right = tmp;
        } else if (s == "West") {
            tmp = top, top = right, right = bottom, bottom = left, left = tmp;
        } else if (s == "South") {
            tmp = top, top = back, back = bottom, bottom = front, front = tmp;
        } else if (s == "Right") {
            tmp = front, front = right, right = back, back = left, left = tmp;
        } else if (s == "Left") {
            tmp = front, front = left, left = back, back = right, right = tmp;
        }
    }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    std::string s;
    Dice c;
    while (std::cin >> n && n) {
        c.reset();
        int total = 1;
        rep(i, n) {
            std::cin >> s;
            c.operation(s);
            total += c.top;
        }
        std::cout << total << std::endl;
    }
}