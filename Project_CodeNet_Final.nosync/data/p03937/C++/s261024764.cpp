#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<vector<bool>>& matrix)
{
    int H = matrix.size();
    int W = matrix[0].size();
    vector<vector<bool>> visit(H, vector<bool>(W, false));
    int w = 0; 
    int h = 0;
    while (true) {
        visit[h][w] = true;
        int next_w = w, next_h = h;
        int step = 0;
        if (w + 1 < W and matrix[h][w + 1]) {
            next_w = w + 1;
            ++step;
        }
        if (h + 1 < H and matrix[h + 1][w]) {
            next_h = h + 1;
            ++step;
        }
        if (step == 0) break;
        if (step > 1) return false;
        w = next_w;
        h = next_h;
    }
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (visit[h][w]) continue;
            if (matrix[h][w]) return false;
        }
    }
    return true;
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> matrix(H, vector<bool>(W, false));
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            char c;
            cin >> c;
            matrix[h][w] = c == '#';
        }
    }
    cout << (check(matrix) ? "Possible" : "Impossible") << endl;
    return 0;
}