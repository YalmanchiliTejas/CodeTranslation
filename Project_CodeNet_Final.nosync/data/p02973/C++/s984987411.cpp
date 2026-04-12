#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;

    std::multiset<int> s;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        
        auto it = s.lower_bound(a);
        if (it != s.begin())
            s.erase(--it);
        s.insert(a);
    }

    std::cout << s.size() << "\n";
}