#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[100];
    for (int i=0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i=100; i >= 1; --i) {
        bool isOk = true;
        int t = 0;
        for (int j=0; j < n; ++j) {
            t += x[j];
            t -= i;
            if (t < 0) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
