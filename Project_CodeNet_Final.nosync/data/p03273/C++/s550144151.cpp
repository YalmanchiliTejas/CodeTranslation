#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h);
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
    }

    std::vector<std::string> t;
    for (int i = 0; i < h; i++) {
        if (std::count(s[i].begin(), s[i].end(), '#')) {
            t.push_back(s[i]);
        }
    }

    std::vector<std::string> u(t.size());
    for (int i = 0; i < w; i++) {
        std::string str;
        for (int j = 0; j < t.size(); j++) {
            str.push_back(t[j][i]);
        }

        if (std::count(str.begin(), str.end(), '#')) {
            for (int j = 0; j < t.size(); j++) {
                u[j].push_back(t[j][i]);
            }
        }
    }

    for (auto str : u) {
        std::cout << str << std::endl;
    }
}
