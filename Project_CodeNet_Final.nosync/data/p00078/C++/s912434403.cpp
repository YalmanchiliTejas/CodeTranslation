#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;

    while (cin >> n, n) {
        int map[15][15];
        int x, y;
        int num = 0;

        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++) 
                map[i][j] = 0;

        x = n / 2;
        y = x + 1;
        map[y][x] = ++num;

        while (num < n * n) {
            bool right = true;
            
            while (true) {
                if (right) 
                    x++;
                else 
                    x--;
                y++;
                
                if (y == n) 
                    y = 0;
                if (x == n)
                    x = 0;
                else if (x == -1)
                    x = n - 1;

                if (map[y][x] != 0) {
                    right = false;
                    continue;
                }
                else {
                    map[y][x] = ++num;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << std::setw(4) << std::right << map[i][j];
            cout << endl;
        }
                
    }

    return 0;
}