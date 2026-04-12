#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 20 + 5;
int h[maxn];

int main()
{
    int n = 0;  cin >> n;
    int temp = -9999;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        temp = max(temp, h[i]);
        if (i)
        {
            if (h[i] >= temp)   ans++;
        }
        else
        {
            ans++;
        }
        
    }
    cout << ans;
    getchar(); getchar();
    return 0;
}