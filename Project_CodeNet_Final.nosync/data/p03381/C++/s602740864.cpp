#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> xsort;
int X[200001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        xsort.push_back(X[i]);
    }

    sort(xsort.begin(), xsort.end());

    int a = xsort[N / 2 - 1];
    int b = xsort[N / 2];
    for (int i = 0; i < N; i++)
    {
        if (X[i] <= a)
            cout << b << "\n";
        else
            cout << a << "\n";
    }

    return 0;
}
