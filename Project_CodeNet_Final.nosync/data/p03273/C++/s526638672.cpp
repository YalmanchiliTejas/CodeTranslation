#include <iostream>
#include <vector>

std::vector<std::vector<int>> vec;
int h, w;
int counter = 0;
std::string s;
int main() {
    std::cin >> h >> w;
    vec.assign(h, std::vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        std::cin >> s;
        for (int p = 0; p < w; p++) {
            if (s[p] == '#') {
                vec[i][p] = 1;
            }
            else if (s[p] == '.') {
                vec[i][p] = 0;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        counter = 0;
        for (int p = 0; p < w; ++p) {
            if (vec[i][p] == 0 || vec[i][p] == -1)
                counter++;
        }
        if (counter == w) {
            for (int p = 0; p < w; ++p) {
                vec[i][p] = -1;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        counter = 0;
        for (int p = 0; p < h; p++) {
            if (vec[p][i] == 0 || vec[p][i] == -1) {
                counter++;
            }
        }
        if (counter == h) {
            for (int k = 0; k < h; k++) {
                vec[k][i] = -1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int p = 0; p < w; p++) {
            if (vec[i][p] == 0) {
                std::cout << ".";
            }
            else if (vec[i][p] == 1) {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }
}
