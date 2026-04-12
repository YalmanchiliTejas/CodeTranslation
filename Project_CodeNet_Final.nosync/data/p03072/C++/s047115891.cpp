#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, count = 0, tmp, max = 0;
    cin >> N;
    while(N--)
    {
        cin >> tmp;
        if(tmp >= max)
        {
            max = tmp;
            count++;
        }
    }
    cout << count;
}
