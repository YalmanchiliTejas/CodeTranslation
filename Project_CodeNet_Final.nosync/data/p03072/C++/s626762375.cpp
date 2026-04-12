#include <iostream>
using namespace std;
int main(void)
{
    int n = 0, tmp = 0, h = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp >= h)
        {
            h = tmp;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}