#include <iostream>
#include <deque>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    deque<int> d;

    int n;
    cin >> n;

    int p = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (p == 0) {
            d.push_back(x);
        }
        else {
            d.push_front(x);
        }
        p = 1 - p;
    }

    if (p == 0) {
        for (auto it = d.begin(); it != d.end(); it++) {
            cout << *it << " ";
        }
    }
    else {
        for (auto it = d.rbegin(); it != d.rend(); it++) {
            cout << *it << " ";
        }
    }

    return 0;
}
