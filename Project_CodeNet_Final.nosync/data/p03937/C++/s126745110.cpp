#include <iostream>
#include <set>
#include <utility>

int h, w;
bool arr[11][11];
bool left[11][11];
int dx[] = {1, 0}, dy[] = {0, 1};

void func(int y, int x) {
    if(y == h && w == x) {
        return;
    }

    left[y][x] = true;
    for(int i = 0; i < 2; ++i) {
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) {
            continue;
        }

        if(arr[ny][nx] && !left[ny][nx]) {
            func(ny, nx);

            return;
        }
    }
}

int main() {
    std::cin >> h >> w;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            char c;
            std::cin >> c;

            arr[i][j] = c == '#';

        }
    }

    func(0, 0);

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(arr[i][j] && !left[i][j]) {
                std::cout << "Impossible" << std::endl;

                return 0;
            }
        }
    }

    std::cout <<"Possible" << std::endl;

}