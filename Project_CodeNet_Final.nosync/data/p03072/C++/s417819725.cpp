#include <iostream>
using namespace std;

int main(void)
{
    int n, h[20], highest;
    int count = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }

    highest = h[0];
    for (int i=0; i<n; i++) {
        if (h[i] >= highest) {
            count += 1;
            highest = h[i];
        }
    }

    cout << count << endl;

    return 0;
}