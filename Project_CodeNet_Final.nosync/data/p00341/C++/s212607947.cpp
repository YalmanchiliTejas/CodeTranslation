#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[15];
    int cnt;
    int f = 1;

    for (int i = 0; i < 12; i++) {
        cin >> a[i];
    }

    sort(a, a + 12);

    for (int i = 0; i < 12; i += 4) {

        cnt = 0;
        int num[105] = {};

        for (int j = i; j < i + 4; j++) {
            if (num[a[j]] == 0) {
                cnt++;
                num[a[j]] = 1;
            }
        }

        if (cnt != 1) {
            f = 0;
        }
    }

    if (f) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
            
    return 0;
}

