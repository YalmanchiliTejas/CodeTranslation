#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string a;
    cin >> a;
    int n = a.size();
    if (n == 1)
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == 'A' && a[i + 1] == 'C')
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
