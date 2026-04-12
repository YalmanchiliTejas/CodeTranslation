#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<int> b(N);
    int l = 0;
    int r = N - 1;
    if (N % 2 == 0)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (i % 2 == 1)
            {
                b[l] = a[i];
                l++;
            }
            else
            {
                b[r] = a[i];
                r--;
            }
        }
    }
    else
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                b[l] = a[i];
                l++;
            }
            else
            {
                b[r] = a[i];
                r--;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}