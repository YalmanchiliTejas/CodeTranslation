#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    string graph[h];
    for (int i = 0; i < h; i++) {
        cin >> graph[i];
    }
    pair<int, int> current;
    while (current != make_pair(h - 1, w - 1)) {
        graph[current.first][current.second] = '.';
        if (current.first + 1 < h && graph[current.first + 1][current.second] == '#') {
            current.first++;
        } else if (current.second + 1 < w && graph[current.first][current.second + 1] == '#') {
            current.second++;
        } else {
            break;
        }
    }
    graph[h - 1][w - 1] = '.';
    bool result = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] == '#') {
                result = false;
            }
        }
    }
    if (result) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }
    return 0;
}