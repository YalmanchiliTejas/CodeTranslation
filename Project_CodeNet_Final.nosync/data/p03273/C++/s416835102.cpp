#include <iostream>
#define MAX 111
using namespace std;

int main() {
    static int m, n;
    static char a[MAX][MAX];
    static bool row[MAX], col[MAX];
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#')
                row[i] = true, col[j] = true;
        }
    for (int i = 0; i < m; ++i) {
        if (row[i]) {
            for (int j = 0; j < n; ++j)
                if (col[j])
                    cout << a[i][j];
            cout << endl;
        }
    }
    
    return 0;
}