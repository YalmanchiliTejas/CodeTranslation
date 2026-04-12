#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int n = 0;
    list<int> b;

    cin >> n;
    int tmp1, tmp2;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            cin >> tmp1 >> tmp2;
            b.push_back(tmp1);
            b.push_front(tmp2);
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            cin >> tmp1 >> tmp2;
            b.push_back(tmp1);
            b.push_front(tmp2);
        }
        cin >> tmp1;
        b.push_back(tmp1);
        reverse(b.begin(), b.end());
    }

    for (list<int>::iterator i = b.begin(); i != b.end(); ++i)
    {
        cout << *i << " ";
    }

    return 0;
}