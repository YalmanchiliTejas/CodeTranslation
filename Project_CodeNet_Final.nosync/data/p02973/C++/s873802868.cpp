#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> A)
{
    vector<int> mx;
    mx.push_back(A.at(0));
    for (int i = 1; i < N; i++)
    {
        int Ai = A.at(i);
        int l = -1, r = mx.size();
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (mx.at(m) < Ai)
                r = m;
            else
                l = m;
        }
        if (r == (int)mx.size())
            mx.push_back(Ai);
        else
            mx.at(r) = Ai;
    }
    cout << mx.size() << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    solve(N, move(A));
    return 0;
}
