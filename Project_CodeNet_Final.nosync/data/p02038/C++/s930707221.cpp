#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char ans, p;
    cin >> ans;
    for (int i = 1; i < n; i++)
    {
        cin >> p;
        if (ans == 'T' && p == 'F')
            ans = 'F';
        else
            ans = 'T';
    }
    cout << ans << endl;
}
