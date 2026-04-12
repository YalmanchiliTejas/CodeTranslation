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

    int tmp = -1;
    for (int i = 0; i < n; i++)
    {
        if(tmp <= h.at(i))
        {
            count++;
            tmp = h.at(i);
        }
    }
    cout << count << endl;
}