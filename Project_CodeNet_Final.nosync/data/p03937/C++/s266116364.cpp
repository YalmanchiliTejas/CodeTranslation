#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, C; cin >> R >> C;

    auto stones = 0;
    for (auto r = 0; r < R; r++) for (auto c = 0; c < C; c++)
    {
        char ch; cin >> ch;
        stones += ch == '#';
    }

    cout << (stones == R+C-1 ? "Possible" : "Impossible") << endl;
}
