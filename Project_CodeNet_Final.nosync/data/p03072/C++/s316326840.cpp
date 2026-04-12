#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> h.at(i);
    }

    int count = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (h.at(i) < h.at(j))
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            count++;
        }
        flag = 0;
    }

    cout << count << endl;

    return 0;
}