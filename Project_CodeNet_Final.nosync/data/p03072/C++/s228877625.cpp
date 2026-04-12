#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, h;
    int m = -1;
    int cnt = 1;
    cin >> n;
    int array[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (size_t i = 1; i < n; i++)
    {
        if(m < array[i]){
            m = array[i];
        }
        if(array[0] <= array[i] && m <= array[i]){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}