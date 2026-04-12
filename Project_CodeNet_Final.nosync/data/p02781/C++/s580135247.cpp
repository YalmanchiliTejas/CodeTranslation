#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    int k;
    cin >> k;
    long long ans = 0;
    for (int i = 1; i < n.size(); i++)
    {
        if (i < k) continue;
        if (k == 1) ans += 9;
        else if (k == 2) ans += 9 * 9 * (i - 1);
        else ans += 9 * 9 * 9 * (i - 1) * (i - 2) / 2;
    }
    string tmp = n;
    for (int i = 0; i < tmp.size(); i++) tmp[i] = '0';
    for (int i = 1; i < 10; i++)
    {
        tmp[0] = i + '0';
        if (k > 1)
        {
            for (int x2 = 1; x2 < tmp.size(); x2++)
            {
                for (int j = 1; j < 10; j++)
                {
                    tmp[x2] = j + '0';
                    if (k > 2)
                    {
                        for (int x3 = x2 + 1; x3 < tmp.size(); x3++)
                        {
                            for (int z = 1; z < 10; z++)
                            {
                                tmp[x3] = z + '0';
                                if (tmp <= n) ans++;
                                tmp[x3] = '0';
                            }
                        }
                    }
                    else
                        if (tmp <= n) ans++;
                    tmp[x2] = '0';
                }
            }
        }
        else
            if (tmp <= n) ans++;
    }
    cout << ans << endl;
}
