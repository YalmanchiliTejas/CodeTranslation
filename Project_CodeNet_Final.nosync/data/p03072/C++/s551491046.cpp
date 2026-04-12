#include <iostream>

using namespace std;

int main()
{
    int n;
    int h[128];
    int max,count;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    count = 1;

    max = h[0];
    for (int i = 1; i < n; i++) {
        if (max <= h[i]) {
            count++;
            max = h[i];
        }
    }

    cout << count << endl;

    return 0;
}