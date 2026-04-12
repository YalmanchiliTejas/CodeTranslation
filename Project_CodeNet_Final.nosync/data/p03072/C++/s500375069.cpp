#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, H1, C = 1;
    cin >> N >> H1;
    vector<int> H(N);
    for (int i = 1; i < N; i++)
    {
        cin >> H.at(i);
        if (H.at(i) >= H1)
        {
            C++;
            H1 = H.at(i);
        }
    }
    cout << C << endl;
}