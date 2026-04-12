#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int a[200000+5];

int main()
{
    int n;
	cin >> n;
    for (int i = 0; i < n; ++i)
    {
        // n-1 1 -> 0
        // n-2 2 -> n-1
        // n-3 3 -> 1
        // n-4 4 -> n-2
        int idx = n-i;
        if (idx % 2 == 1)
            idx /= 2;
        else
            idx = n - idx/2;
        cin >> a[idx];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
	return 0;
}
