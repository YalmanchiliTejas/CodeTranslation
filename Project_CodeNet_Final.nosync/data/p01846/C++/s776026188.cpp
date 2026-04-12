#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main() {
    int a, b, c, d;
    std::vector<std::vector<char>> field;

    while (1) {
        field.clear();
        std::string raw_field;
        std::cin >> raw_field;
        if (raw_field == "#") return 0;
        field.push_back(std::vector<char>());
        for (char c : raw_field) {
            if (std::isdigit(c)) {
                for (int i = 0; i < c - '0'; i++) {
                    field.back().push_back('.');
                }
            }
            else if (c == 'b') {
                field.back().push_back('b');
            }
            else if (c == '/') {
                field.push_back(std::vector<char>());
            }
        }

        std::cin >> a >> b >> c >> d;

        field[a-1][b-1] = '.';
        field[c-1][d-1] = 'b';

        raw_field = "";
        for (auto field_line : field) {
            int dot_count = 0;
            for (auto point : field_line) {
                if (point == '.') {
                    dot_count++;
                }
                else if (point == 'b') {
                    if (dot_count) {
                        raw_field += std::to_string(dot_count);
                    }
                    dot_count = 0;
                    raw_field += 'b';
                }
            }
            if (dot_count) {
                raw_field += std::to_string(dot_count);
            }
            raw_field += "/";
        }
        raw_field.pop_back();
        std::cout << raw_field << std::endl;
    }

    return 0;
}
