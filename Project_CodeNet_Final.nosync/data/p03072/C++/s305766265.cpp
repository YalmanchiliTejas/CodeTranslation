#include <bits/stdc++.h>

using namespace std;

int a[105];

int main()
{
    int n, i, sum = 1;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(i != 1)
        {
            if(a[i] >= a[i-1])
                sum++;
            else
                a[i] = a[i-1];
        }
    }
    cout << sum << endl;
    return 0;
}
