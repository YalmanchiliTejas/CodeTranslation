#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    char a[60];
    int n, num[30] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp[30] = {};
        cin >> a;
        for (int j = 0; j < strlen(a); j++)
        {
            if (i == 0)
                num[a[j] - 'a']++;
            else
                tmp[a[j] - 'a']++;
        }
        if (i > 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (tmp[j] < num[j])
                    num[j] = tmp[j];
            }
        }
    }
    string ans = {};
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            ans += 'a' + i;
        }
    }
    cout << ans << endl;
    return 0;
}