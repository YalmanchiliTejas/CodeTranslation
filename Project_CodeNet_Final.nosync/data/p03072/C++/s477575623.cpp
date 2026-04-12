#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    int n, sum = 1, k = 0;
    cin >> n;
    vector <int> h(n, 0);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 1; i < n; i++) {
        k = 0;
        for (int j = 0; j < i; j++){
            if (h[j] > h[i]) k++;
        }
        if (k == 0) sum++;
    }
    cout << sum << endl;

    return 0;
}
