#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

void delete_empty_rows(std::vector<std::string>& lines) {
    std::string empty_row(lines.front().size(), '.');
    lines.erase(std::remove(lines.begin(), lines.end(), empty_row), lines.end());
}

void transpose(std::vector<std::string>& lines) {
    const size_t H = lines.size(), W = lines.front().size();
    std::vector<std::string> tr_lines(W, std::string(H, '\0'));
    for (size_t i = 0; i < H; ++i) {
        for (size_t j = 0; j < W; ++j) {
            tr_lines[j][i] = lines[i][j];
        }
    }
    lines = std::move(tr_lines);
}

void print(const std::vector<std::string>& lines) {
    for (const auto& line : lines) {
        std::printf("%s\n", line.c_str());
    }
}

int main() {
    int H, W;
    std::scanf("%d %d\n", &H, &W);

    std::vector<std::string> lines(H, "");
    for (auto& line : lines) {
        line.resize(W);
        std::scanf("%s\n", &line[0]);
    }

    delete_empty_rows(lines);
    transpose(lines);
    delete_empty_rows(lines);
    transpose(lines);
    print(lines);
}
