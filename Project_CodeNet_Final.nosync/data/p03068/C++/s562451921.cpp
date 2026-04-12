#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    int n, k;

    cin >> n >> s >> k;

    for (int i = 0; i < n; i++) {
        if (s[k-1] != s[i]) {
            s[i] = '*';
        }
    }

    cout << s << endl;
}
