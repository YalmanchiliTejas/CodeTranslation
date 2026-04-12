#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n = 0;
    int num = 1;
    int i = 0, j = 0;
    cin >> n;
    vector<int> highest(n);
    for (i = 0; i < n; i++)
        cin >> highest[i];
    for (i = 1; i < n; i++)
    {
        int high = highest[i];
        bool is_ok = true;
        for (j = 0; j < i; j++)
        {
            if (highest[j] > high)
            {
                is_ok = false;
            }
        }
        if (is_ok)
            num++;
    }
    cout << num << endl;
    return 0;
}