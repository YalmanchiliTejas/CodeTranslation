#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> B;
    B.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        auto it = upper_bound(B.begin(), B.end(), a, greater<>());
        if (it == B.end())
        {
            B.push_back(a);
        } else
        {
            *it = a;
        }
    }

    cout << B.size() << "\n";


}
