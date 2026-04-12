#include <bits/stdc++.h>
using namespace std;


bool search(int x, int y, vector<string> board, vector<pair<int, int>> path) {
    if (y == board.size()-1 && x == board[0].size()-1) {
        path.push_back(make_pair(x, y));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                if (board[i][j] == '#') {
                    auto p = make_pair(j, i);
                    if (find(path.begin(), path.end(), p) == path.end()) return false;
                } 
            }
        }
        return true;
    } else {
        if (y == board.size() - 1) {
            if (board[y][x+1] == '.') return false;
            else {
                auto p = make_pair(x, y);
                path.push_back(p);
                return search(x+1, y, board, path);
            }
        } else if (x == board[0].size() - 1) {
            if (board[y+1][x] == '.') return false;
            else {
                path.push_back(make_pair(x, y));
                return search(x, y+1, board, path);
            }
        } else {
            path.push_back(make_pair(x, y));
            if (board[y+1][x] == '.' && board[y][x+1] == '.') return false;
            else if (board[y+1][x] == '#' && board[y][x+1] == '.') return search(x, y+1, board, path);
            else if (board[y+1][x] == '.' && board[y][x+1] == '#') return search(x+1, y, board, path);
            else return (search(x+1, y, board, path) || search(x, y+1, board, path));
        }
    }
}

int main() {
    vector<string> board;
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string line;
        cin >> line;
        board.push_back(line);
    }

    //for (string line : board) cout << line << endl;
    vector<pair<int, int>> path;
    if (search(0, 0, board, path)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}