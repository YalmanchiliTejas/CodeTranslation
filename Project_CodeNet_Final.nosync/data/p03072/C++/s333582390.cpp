#include<bits/stdc++.h>
using namespace std;

int num[23333];

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (num[i] >= maxx)
            ans++, maxx = num[i];
    }
    cout << ans;
    return 0;
}