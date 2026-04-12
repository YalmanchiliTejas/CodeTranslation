#include <iostream>
#include <deque>

int main()
{
    int n;
    std::cin >> n;
    std::deque<int> dq;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (i & 1)
            dq.push_back(a);
        else
            dq.push_front(a);
    }

    bool rev = !(n & 1);
    while (!dq.empty()) {
        int top;
        if (rev) {
            top = dq.back();
            dq.pop_back();
        }
        else {
            top = dq.front();
            dq.pop_front();
        }
        std::cout << top << " ";
    }
    std::cout << std::endl;
    return 0;
}