#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main() {
    int n, m;
    std::vector<std::vector<int>> e;

    std::cin >> n >> m;
    e.reserve(n+10);
    for (int i = 0; i < n + 2; i++) {
        e.push_back(std::vector<int> {});
    }

    for (int i = 0; i < m; i++) {
        int a,b;
        std::cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int ret = 0;
    std::deque<std::vector<int>> q {{1}};
    while (true) {
        if (q.empty()) break;

        auto visited = std::vector<int>(q.front());
        auto current = visited.back();

        if (visited.size() == n) {
            ret++;
            q.pop_front();
            continue;
        }

        for (const auto next : e[current]) {
            if (std::find(visited.begin(), visited.end(), next) == visited.end()) {
                auto pushvec = std::vector<int>(visited);
                pushvec.push_back(next);
                q.push_back(pushvec);
            }
        }

        q.pop_front();
    }

    std::cout << ret << std::endl;

    return 0;
}