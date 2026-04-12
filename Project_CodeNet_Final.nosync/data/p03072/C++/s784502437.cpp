#include <bits/stdc++.h>
using namespace std;

vector<int> h(100);
vector<int> a(100);
int counts = 0;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h.at(i);

    int maxh = 0;
    for (int i = 0; i < n; ++i)
    {
        maxh = max(h.at(i), maxh);
        a.at(i) = maxh;
    }

    for (int i = 0; i < n; ++i)
    {
        if (h.at(i) >= a.at(i))
        {
            counts++;
        }
    }

    cout << counts << endl;
}