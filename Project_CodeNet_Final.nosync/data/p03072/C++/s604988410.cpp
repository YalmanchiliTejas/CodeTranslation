#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flag;
    int answer = 0;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (h.at(j) > h.at(i))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            answer++;
        }
        else
        {
            flag = 0;
        }
    }
    cout << answer << endl;
    return 0;
}