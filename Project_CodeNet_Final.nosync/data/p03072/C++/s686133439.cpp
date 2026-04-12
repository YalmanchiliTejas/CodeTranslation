#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> mt;
    mt.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mt[i];
    }

    int max = mt[0];
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (mt[i] >= max)
        {
            cnt++;
            max = mt[i];
        }
    }

    cout << cnt << endl;

    return 0;
}
