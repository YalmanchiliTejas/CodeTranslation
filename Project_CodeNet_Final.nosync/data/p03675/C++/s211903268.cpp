#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdio.h>

#define _ << " " <<
#define debug(x) #x << " = " << x

#define ll long long
#define ull unsigned long long

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::deque<int> deck;

    bool end = true;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (end) {
            deck.push_back(x);
        } else {
            deck.push_front(x);
        }

        end = !end;
    }

    if (end) {
        auto it = deck.begin();
        while(it != deck.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }

    if (!end) {
        auto it = deck.rbegin();
        while(it != deck.rend()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
    return 0;
}