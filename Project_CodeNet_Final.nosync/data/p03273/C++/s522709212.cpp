// https://beta.atcoder.jp/contests/abc107

#define SUBMIT
#define DEBUG

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <map>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_SIDE = 100;
int H, W;
char field[MAX_SIDE][MAX_SIDE];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(7 6
......
....#.
.#....
..#...
..#...
......
.#..#.
)";
    stringstream stream(program_input_str);
#endif
    stream >> H >> W;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            stream >> field[y][x];
        }
    }

    vector<int> print_rows;
    for (int y = 0; y < H; ++y) {
        bool contains_black = false;
        for (int x = 0; x < W; ++x) {
            if (field[y][x] == '#') contains_black = true;
        }

        if (contains_black) print_rows.push_back(y);
    }

    vector<int> print_cols;
    for (int x = 0; x < W; ++x) {
        bool contains_black = false;
        for (int y = 0; y < H; ++y) {
            if (field[y][x] == '#') contains_black = true;
        }

        if (contains_black) print_cols.push_back(x);
    }

    for (auto y : print_rows) {
        for (auto x : print_cols) {
            cout << field[y][x];
        }
        cout << endl;
    }
    return 0;
}