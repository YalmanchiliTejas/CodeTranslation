#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> h;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        h.push_back(x);
    }
    int count = 0;
    for(int i = n - 1;i >= 0;i--)
    {
        int max = 0;
        for(int j = 0;j < i;j++)
        {
            if(h[j] > max)
            {
                max = h[j];
            }
        }
        if(h[i] >= max)
        {
            count++;
        }
    }
    cout << count;

    return 0;
}