#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int m1, m2;

    vector<long long int> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long int> s(x);

    sort(s.begin(), s.end());

    m1 = s[n/2];
    m2 = s[(n/2)-1];

    for (int i = 0; i < n; i++) {
        if (x[i] >= m1) {
            cout << m2 << endl;
        }
        else if (x[i] <= m2) {
            cout << m1 << endl;
        }
    }
}
