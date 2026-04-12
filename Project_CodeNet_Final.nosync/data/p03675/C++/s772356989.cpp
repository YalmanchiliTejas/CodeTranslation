#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<int> b;
    for (int i = N - 1; i >= 0; i -= 2)
        b.push_back(a[i]);
    for (int i = (N % 2 != 0); i < N; i += 2)
        b.push_back(a[i]);

    for (int i = 0; i < N; ++i) {
        if (i > 0)
            cout << ' ';
        cout << b[i];
    }
    cout << '\n';
    return 0;
}
