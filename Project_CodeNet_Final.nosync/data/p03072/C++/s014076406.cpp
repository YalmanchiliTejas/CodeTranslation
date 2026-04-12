#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h.at(i);
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if(h.at(j) > h.at(i))
            {
                flag = false;
            }
        }
        if(flag)
            {
                count++;
            }
    }
    cout << count << endl;
}