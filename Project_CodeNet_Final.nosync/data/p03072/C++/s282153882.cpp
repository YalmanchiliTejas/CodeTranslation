#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec.at(i);
    }

    int max = vec.at(0);
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (max <= vec.at(i))
        {
            cnt++;
            max = vec.at(i);
        }
    }
    cout << cnt << endl;
}