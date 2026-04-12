#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int cnt = 1;

    for (int j = 1; j < n; j++) {    
        int flag = 0;
        for (int i = 0; i < j; i++) {
            if (h[j] < h[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cnt = cnt + 1;
    }

    cout << cnt << endl;
    return 0;
}