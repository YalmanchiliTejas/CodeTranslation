#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;

    int count=0;
    vector<int> data(n);
    rep(i, n)
    {
        cin >> data[i];
        int flag=0;
        rep(j, i)
        {
            if (data[j] > data[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            count += 1;
        }
    }
    cout <<count<<endl;
}