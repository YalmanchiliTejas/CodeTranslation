#include <algorithm>
#include <iostream>
#include <vector>

#define FOR(a, b) for (int i = a; i < b; ++i)
#define FOR_EACH(container) for (const auto& p: container)
#define SORT(container) sort(container.begin(), container.end())
#define DSORT(container) sort(container.begin(), container.end(), greater<>())

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    string str;

    cin >> N >> str >> K;

    str.reserve(N);

    auto pivot = str[K - 1];

    for (auto& ch: str)
    {
        if (ch != pivot)
        {
            ch = '*';
        }
    }

    cout << str << "\n" << flush;

    return 0;
}
