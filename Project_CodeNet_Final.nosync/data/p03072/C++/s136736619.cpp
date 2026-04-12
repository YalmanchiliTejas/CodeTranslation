#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h;
    int tmp;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        h.push_back(tmp);
    }

    int max_hight = h[0];
    int c = 0;

    for (int i = 0; i < n; ++i) {
        if (h[i] >= max_hight) {
            ++c;
            max_hight = h[i];
        }
    }

    cout << c << endl;
}
