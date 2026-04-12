#include <iostream>
#include <algorithm>
using namespace std;

int p, s, n = 0, q;
pair<int, int> t[100];
int r[101];
char c;

int main()
{
    while (1) {
        cin >> p >> c >> s;

        if (p == 0 && s == 0)
            break;

        t[n].first = s;
        t[n].second = p;
        n++;
    }

    sort(t, t + n, greater<pair<int, int> >());

    r[t[0].second] = 1;
    int j = 1;

    for (int i = 1; i < n; i++) {
        if (t[i].first < t[i - 1].first)
            j++;

        r[t[i].second] = j;
    }

    while (cin >> q)
        cout << r[q] << endl;

    return 0;
}

