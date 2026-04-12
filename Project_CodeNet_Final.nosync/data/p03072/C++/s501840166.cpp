#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n+2];
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int flag = 0;
        for(int j = 0; j < i; j++)
        {
            if(a[i] < a[j])
            {
                flag = 1;
                break;
            }
        }
        if(!flag) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}

