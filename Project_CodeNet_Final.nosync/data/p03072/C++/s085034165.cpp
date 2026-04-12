#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool flag = false;
    int n, num = 1;
    vector<int> h;

    cin >> n;
    h.resize(n);
    for (auto & elem:h) cin >> elem;

    for (int i = n - 1; i > 0; --i) {
        flag = true;
        for (int j = i - 1; j >= 0; --j) {
            if (h[i] - h[j] < 0) flag = false;
        }
        if (flag) ++num;
    }
    cout << num << endl;
}