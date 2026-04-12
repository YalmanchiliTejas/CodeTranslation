#include <iostream>
#include <string>
#include <cmath>

#include <list>
#include <queue>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main(void)
{
    int n, m;

    int connection[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            connection[i][j] = 0;
        }
    }

    int array[] = {2,3,4,5,6,7,8};

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        connection[a][b] = 1;
        connection[b][a] = 1;
    }

    int count = 0;

    do {
        bool flag = true;
        if (connection[1][array[0]] == 1) {
            for (int i = 0; i < n - 2; i++) {
                int current = array[i];
                // cout << current << " ";
                // auto itr = find(connection[current].begin(), connection[current].end(), array[i + 1]);
                
                if (connection[current][array[i + 1]] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
        // cout << endl;
    } while (next_permutation(array, array + n - 1));

    cout << count;
    
    return 0;
}
