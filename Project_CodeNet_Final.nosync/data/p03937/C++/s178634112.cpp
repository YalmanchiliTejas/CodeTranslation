#include <iostream>

using namespace std;

int main()
{
    int a, b;
    char m[12][12];
    int cnt = 0;

    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (m[i][j] == '#') cnt++;
        }
    }

    if (cnt == a+b-1) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
