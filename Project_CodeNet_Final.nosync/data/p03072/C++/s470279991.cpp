#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> H(N);
    vector<int> I(N);

    int counter = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> H[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (H[i] < H[j])
                I[i] = 1;
        }
        counter = counter + I[i];
    }

    cout << N - counter << endl;
    return 0;
}